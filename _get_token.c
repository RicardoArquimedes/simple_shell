#include "shell.h"
/**
 * _get_token - get token of string
 * @lineptr: comman user
 * Return : pointer
 */

char **_get_token(char *lineptr)
{
	char *symbol = " \n";
	char *token;
	int size = 128, i = 0;

	char **user_command = malloc(sizeof(char *) * size);

	if (user_command == NULL)
		exit(EXIT_FAILURE);

	token = strtok(lineptr, symbol);
	for (i = 0; i < 10 && token != NULL; i++)
	{
		user_command[i] = token;
		token = strtok(NULL, symbol);
	}
	user_command[i] = NULL;
	return (user_command);
}
