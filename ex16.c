#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>


// A structure in C is a collection of other data types that are stored in one block of memory
// You can access each variable independently by name

struct Person {
	char *name;
	int age;
	int height;
	int weight;
};


struct Person *Person_create(char *name, int age, int height, int weight)
{
	struct Person *who = malloc(sizeof(struct Person));
	//to make sure I receive a valid piece of memory back from malloc
	assert(who != NULL);
	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;

	return who;
}

void Person_destroy(struct Person *who)
{
	assert(who != NULL);
	free(who->name);
	free(who);
}

void Person_print(struct Person *who)
{
	printf("Name: %s\n", who->name);
	printf("\tAge: %d\n", who->age);
	printf("\tHeight: %d\n", who->height);
	printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char *argv[])
{
	struct Person *joe = Person_create("Joe Alex", 32, 64, 140);
	struct Person *frank = Person_create("Frank Blank", 20, 72, 180);

	printf(" Joe is at memory location %p: \n", joe);
	Person_print(joe);

	printf(" Frank is at memory location %p: \n", frank);
	Person_print(frank);

	joe->age += 60;
	joe->height -= 2;
	joe->weight += 40;
	Person_print(joe);

	frank->age += 20;
	frank->weight += 20;
	Person_print(frank);

	return 0;
}