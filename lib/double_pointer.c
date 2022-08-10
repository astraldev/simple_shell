/*
* Created by ifiokekott on 8/6/22.
*/
#include "double_pointer.h"

char **copy_double_pointer(char **double_pointer, int plus_size)
{
	size_t size, iter;
	char **new_db_ptr;

	for (size = 0; double_pointer[size]; size++)
		;
	size += plus_size;
	new_db_ptr = malloc(sizeof(char *) * (size));
	for (iter = 0; double_pointer[iter]; iter++)
		new_db_ptr[iter] = strdup(double_pointer[iter]);

	new_db_ptr[size] = NULL;
	return (new_db_ptr);
}

int print_double_pointer(char **double_ptr)
{
	unsigned int iteration;

	for (iteration = 0; double_ptr[iteration] != NULL; iteration++)
		printf("%d: %s\n", iteration, double_ptr[iteration]);

	return(0);
}

int free_double_pointer(char **db_ptr)
{
	unsigned int size;
	size_t iteration;

	for (size = 0; db_ptr[size]; size++)
		;

	for (iteration = 0; iteration < size; iteration++)
		free(db_ptr[iteration]);

	free(db_ptr);
	return (0);
}
