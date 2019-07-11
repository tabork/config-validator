
from django.contrib import admin

from .models import Bee, Result

# Register your models here.
class BeeAdmin(admin.ModelAdmin):
	exclude = ('slug','secret_key','status')

admin.site.register(Bee, BeeAdmin)

admin.site.register(Result)
