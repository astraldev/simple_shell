#include "parse_string.h"

char **parse_string(char *str, char *delimiter)
{
	int iteration, no_delimiter, k;
	char *token;
	char **parsed, *buffer = strdup(str);

	/**
	* calculates the number of tokens for the string
	*/
	for (iteration = 0, no_delimiter = 0, k = 0; str[iteration]; iteration++)
	{
		if (str[iteration] == *delimiter)
			no_delimiter++;
	}

	parsed = malloc(sizeof(char *) * (no_delimiter + 2));
	token = strtok(buffer, delimiter);

	if (parsed == NULL)
		return (NULL);
	while (token)
	{
		parsed[k] = malloc((strlen(token) + 1));
		strcpy(parsed[k++], token);
		token = strtok(NULL, delimiter);
	}
	parsed[k] = NULL;

	free(buffer);
	return (parsed);
}