#include <stdio.h>

int main (int argc, char *argv[])
{
	
	// creates two basic arrays
	//line 8 is an array of ints
	int ages[] = {23, 43, 12, 89, 2};
	//line 10 is an array of strings
	char *names[] = {
		"Alan", "Frank",
		"Mary", "John", "Lisa"
	};

	int count = sizeof(ages) / sizeof(int);
	int i = 0;

	for (int i = 0; i < count; ++i)
	{
		printf("%s has %d years alive.\n", names[i], ages[i] );
	}

	printf("---\n");

	int *cur_age = ages;
	char **cur_name = names;

	for (int i = 0; i < count; ++i)
	{
		printf("%s is %d years old. \n", *(cur_name+i), *(cur_age+i) );
	}

	printf("---\n");

	for (int i = 0; i < count; ++i)
	{
		printf("%s is %d years old again. \n", cur_name[i], cur_age[i]);
	}

	printf("---\n");

	for(cur_name = names, cur_age = ages; (cur_age - ages) < count; cur_name++, cur_age++)

	{
		printf("%s has lived %d years so far. \n", *cur_name, *cur_age);
	}

	return 0;

}