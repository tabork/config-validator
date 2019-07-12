
import json

from django.shortcuts import render, redirect

# Create your views here.
from .models import Bee, Result
from .forms import AddBeeForm

from queen_app.tasks import send_request

def index(request):
	if request.user.is_authenticated:
		template = 'queen/index.html'
		bees = Bee.objects.all().order_by('name')

		context = {
			'bees': bees
		}

		return render(request, template, context)
	else:
		template = 'queen/index_noauth.html'

		return render(request, template)

def add_bee(request):
	if not request.user.is_authenticated:
		return redirect('/')
	template = 'queen/add_bee.html'

	form = AddBeeForm(request.POST or None)

	if form.is_valid():
		form.save(commit=True)
		return redirect('/')
	else:
		form = AddBeeForm()

	context = {
		'form': form
	}

	return render(request, template, context)

def parse_result(j):
	s = json.loads(j)
	out = ''
	for scan in s['scans']:
		t = scan['type']
		out += '<h2 class="subheading">'+ t + '</h2>\n'
		for file in scan['files']:
			out += file['name'] + ' = ' + file['J'] + '<br>\n'
		out += '<br>\n';
	return out

def view_bee(request, slug):
	if not request.user.is_authenticated:
		return redirect('/')

	template = 'queen/view_bee.html'

	try:
		bee = Bee.objects.get(slug=slug)
	except Bee.DoesNotExist:
		return redirect('/')

	if bee.status == 'Complete':
		result = Result.objects.get(bee=bee)
		body = parse_result(result.result)
	elif bee.status == 'Scanning':
		body = 'Still scanning'
	else:
		body = 'Needs scanned'

	context = {
		'bee': bee,
		'body': body
	}

	return render(request, template, context)

def scan_bee(request, slug):
	if not request.user.is_authenticated:
		return redirect('/')

	try:
		bee = Bee.objects.get(slug=slug)
	except Bee.DoesNotExist:
		return redirect('/')

	send_request.delay(bee.id)
	return redirect('queen_app:bee', slug=slug)

