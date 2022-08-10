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

user_input_type *parse_multiline(char **env)
{
	char *user_input = NULL, *parsed_str, *delim;
	size_t max_len = BUFSIZ, iter1 = 0;
	int *control_values;
	user_input_type *list = NULL;

	prompt(env);
	if (getline(&user_input, &max_len, stdin) <= 0)
		return (NULL);
	user_input[strlen(user_input) - 1] = '\0';
	control_values = find_control(user_input);
	if (*control_values)
	{
		if (*control_values == 1)
			delim = "&&";
		else if (*control_values == -1)
			delim = "||";
		parsed_str = strtok(user_input, delim);
		while (parsed_str)
		{
			add_input_string(&list, control_values[iter1++], parsed_str);
			parsed_str = strtok(NULL, delim);
		}
		free(user_input);
	}
	else
	{
		list = add_input_string(&list, 0, user_input);
		free(user_input);
	}
	free(control_values);
	return (list);
}