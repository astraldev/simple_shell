/*
* Created by ifiokekott on 8/7/22.
*/

#include "add_node_list.h"

/**
 * add_node - adds a node pointer
 *
 * @head: the pointer to the head pointer
 * @str: the new str
 * Return: list_t*
 */
list_t *add_node(list_t **head, int value)
{
	list_t *newNode;
	/*size_t strLen;*/

	newNode = malloc(sizeof(list_t));
	if (!newNode)
		return (NULL);
	newNode->value = value;
	newNode->next = *head;
	*head = newNode;

	return (*head);
}