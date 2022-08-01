#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * new_dog - creates a new dog
 * @name: pointer to dog name string
 * @age: dog age
 * @owner: pointer to dog owner name string
 *
 * Return: pointer to the newly created dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *ptr;

	ptr = malloc(sizeof(dog_t));
	if (ptr == NULL)
	{
		return (NULL);
	}

	/*ptr->name = malloc(sizeof(char *));*/
	ptr->name = name;

	ptr->age = age;

	/*ptr->owner = malloc(sizeof(char *));*/

	ptr->owner = owner;

	return (ptr);
}
