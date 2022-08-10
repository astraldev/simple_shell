/*
* Created by ifiokekott on 8/4/22.
*/

#include "lib/sub_main.h"


int main(
	int ac __attribute__((unused)),
	char **av __attribute__((unused)),
	char **env
)
{
	int exit_status = 0;
	char **history = NULL;
	list_t *head = NULL;

	head = NULL;
	history = malloc(sizeof(char *) * 2);
	history[0] = NULL;

	while (1) if (sub_main(env, &exit_status, &history, &head)) break;

	if (history)
		free_double_pointer(history);
	if (head != NULL)
		free_list(head, env);
	exit(exit_status);

	return (0);
}
