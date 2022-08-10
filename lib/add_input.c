
#include "add_input.h"

int add_input_history(char ****history, char *string)
{
	unsigned int iter = 0;


	if (!(**history))
	{
		**history = malloc(sizeof(char *) * 2);
	}
	else
	{
		for (; (**history)[iter]; iter++)
			;
		**history = realloc(**history, sizeof(char *) * (iter + 2));
	}


	(**history)[iter++] = strdup(string);
	(**history)[iter] = NULL;

	return (0);
}

/**
 * add_input_string - adds a node pointer
 *
 * @head: the pointer to the head pointer
 * @str: the new str
 * Return: list_t*
 */

user_input_type *add_input_string(user_input_type **head, int control, char *input)
{
	user_input_type *new_node, *buffer;

	new_node = malloc(sizeof(user_input_type));
	if (!new_node)
		return (NULL);
	new_node->string = strdup(input);
	new_node->add_or = control;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		buffer = *head;
		while (buffer->next)
			buffer = buffer->next;
		buffer->next = new_node;
	}

	return (*head);
}