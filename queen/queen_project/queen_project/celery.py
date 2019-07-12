
import os

from celery import Celery

os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'queen_project.settings')

app = Celery('queen_project')
app.config_from_object('django.conf:settings')

app.autodiscover_tasks()
