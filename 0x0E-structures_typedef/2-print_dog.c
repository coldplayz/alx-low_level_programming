#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * print_dog - prints object of type 'struct dog'
 * @d: pointer to the struct dog variable to print
 */
void print_dog(struct dog *d)
{
	if (d != NULL)
	{
		printf("Name: %s\nAge: %f\nOwner: %s\n",
				(d->name == NULL ? "(nil)" : d->name),
				((d->age == 0) ? 0 : d->age),
				(d->owner == NULL ? "(nil)" : d->owner));
	}
}
