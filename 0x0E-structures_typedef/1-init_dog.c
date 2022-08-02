#include "main.h"
#include <stdlib.h>
#include "dog.h"
#include <stdio.h>

/**
 * init_dog - initializes a variable of type 'struct dog'
 * @d: a pointer to the structure
 * @name: a pointer to the dog name string
 * @age: the dog's age as float
 * @owner: a pointer to the owner name string
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
	{
		printf("Ok");
	}
	d->name = name;
	d->age = age;
	d->owner = owner;
}
