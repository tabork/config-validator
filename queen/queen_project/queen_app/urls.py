
from django.urls import path

from .views import index, add_bee, view_bee

app_name = 'queen_app'

urlpatterns = [
	path('', index, name='index'),
	path('add-bee/', add_bee, name='add_bee'),
	path('bee/<slug:slug>/', view_bee, name='bee')
]