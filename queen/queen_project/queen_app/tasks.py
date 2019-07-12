
import logging, jwt, requests

from django.urls import reverse
from django.contrib.auth import get_user_model
from queen_project.celery import app

from queen_app.models import Bee, Result

# TODO https
def build_request(address, secret_key):
	payload = {'run':'scan'}
	encoded_jwt = jwt.encode(payload, secret_key, algorithm='HS256')
	return 'http://' + address + ':3000/' + encoded_jwt.decode('utf-8')

@app.task
def send_request(bee_id):
	bee = Bee.objects.get(id=bee_id)
	r = build_request(bee.address, bee.secret_key)
	bee.status = 'Scanning'
	bee.sub_save()

	response = requests.get(url=r)
	result, created = Result.objects.get_or_create(bee=bee)
	result.result = response.content.decode('utf-8')
	result.save()
	bee.status = 'Complete'
	bee.sub_save()

