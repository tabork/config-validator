from django.shortcuts import render, redirect

# Create your views here.
from .models import Bee, Result
from .forms import AddBeeForm

def index(request):
	template = 'queen/index.html'

	return render(request, template)

def add_bee(request):
	# TODO add auth
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