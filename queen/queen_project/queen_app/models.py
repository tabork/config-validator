
from django.db import models
from django.template.defaultfilters import slugify
from django.utils.crypto import get_random_string

# Create your models here.
class Bee(models.Model):
	name = models.CharField(max_length=100, unique=True)
	description = models.CharField(max_length=250, blank=True)
	address = models.CharField(max_length=16, unique=True)
	slug = models.SlugField(max_length=200, unique=True)
	status_choices = [
		('Not Scanned', 'Not Scanned'),
		('Scanning', 'Scanning'),
		('Complete', 'Complete')
	]
	secret_key = models.CharField(max_length=32, unique=True)
	status = models.CharField(max_length=12, choices=status_choices, 
		                      default='Not Scanned')

	def save(self, *args, **kwargs):
		self.slug = slugify(self.name)
		self.secret_key = get_random_string(length=32)
		super(Bee, self).save(*args, **kwargs)

class Result(models.Model):
	bee = models.ForeignKey(Bee, on_delete=models.CASCADE)
	result = models.TextField()