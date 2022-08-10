/*
* Created by ifiokekott on 8/5/22.
*/

#include "env_variables.h"

char *get_env_variable(char **environment, char *variable)
{
	unsigned int iteration, size_env;
	char *path = NULL, *buffer, *delimiter = "=", *result;

	for (size_env = 0; environment[size_env]; size_env++)
		;

	for (iteration = 0; strncmp(environment[iteration], variable, strlen(variable)); iteration++)
	{
		if ((iteration+1) == size_env)
			return (NULL);
	}
	buffer = strdup(environment[iteration]);
	path = strtok(buffer, delimiter);
	path = strtok(NULL, delimiter);
	result = strdup(path);
	free(buffer);
	return (result);
}

int set_env_variable(char **environment, char *variable, char *value, list_t **head)
{
	unsigned int iteration, size_env;

	for (size_env = 0; environment[size_env]; size_env++)
		;
	for (iteration = 0; strncmp(environment[iteration], variable, strlen(variable)); iteration++)
	{
		if ((iteration+1) == size_env)
		{
			iteration++;
			break;
		}
	}
	if (iteration == size_env) {
		environment[iteration] = malloc(sizeof(char) * (strlen(value) + strlen(variable) + 2));
		add_node(head, iteration);
	}
	strcat(strcpy(environment[iteration], variable), "=");
	strcat(environment[iteration], value);
	if (iteration == size_env)
		environment[iteration+1] = NULL;
	return (0);
}

int print_env(char **env, char *string __attribute__((unused)), list_t **head __attribute__((unused)))
{
	print_double_pointer(env);
	return (0);
}