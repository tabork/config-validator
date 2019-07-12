
from django import forms

from .models import Bee

class AddBeeForm(forms.ModelForm):
	class Meta:
		model = Bee
		fields = ['name', 'description', 'address']
		widgets = {
			'name': forms.TextInput(attrs={'class': 'form-control'}),
			'description': forms.Textarea(attrs={'class': 'form-control'}),
			'address': forms.TextInput(attrs={'class': 'form-control'})
		}