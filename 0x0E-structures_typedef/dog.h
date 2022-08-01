#ifndef dog_h
#define dog_h

/**
 * struct dog - defines a new type
 * @name: a pointer to the dog name in string format
 * @age: represents the dog's age
 * @owner: a pointer to the name of the owner of the dog
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

#endif /*dog_h*/
