#include "shell.h"
/**
 * _getline_command - print "#cisfun$ " and wait for the user type something.
 * Return: line of string input for user
 */

char *_getline_command(void)
{
	char *lineptr = NULL;
	size_t charter_user = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "#cisfun$ ", 10);

	if (getline(&lineptr, &charter_user, stdin) == EOF)
	{
		free(lineptr);
		return (NULL);
	}

	return (lineptr);
}
