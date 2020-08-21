#include "shell.h"
/**
 * _getline_command - print "#cisfun$ " and wait for the user type something.
 * Return: line of string input for user
 */

char *_getline_command(void)
{
	char *lineptr = NULL;
	size_t charter_user = 0;

	if (isatty(STDIN_FILENO))//si el documento esta asociado a un dispoditipo terminal shell
		write(STDOUT_FILENO, "$ ", 2);

	if (getline(&lineptr, &charter_user, stdin) == -1)//no asocio docuemnto liber memoria
	{
		free(lineptr);
		return (NULL);
	}

	return (lineptr);//retorna input de usuario(solo sabe que ingreso, pero no sabe si es un comando erros o que ?)
}
