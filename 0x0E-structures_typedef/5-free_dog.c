#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - frees dogs (the structure)
 * @d: pointer to struct to free
 */
void free_dog(dog_t *d)
{
	if (d == NULL)
	{
		exit(EXIT_SUCCESS);
	}
	free(d->name);
	free(d->owner);
	free(d);
}
