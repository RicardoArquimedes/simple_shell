#include "shell.h"

/**
 * exit_command - this function closes the prompt when the exit cmd is passed
 * @args: Pointer with the direction to free  the allocated memory for
 * the  arguments passed to the program.
 * Return: None
 */
void exit_command(char **args, char *lineptr, int _exit)
{
	int exit_status = 0;

	if (!arg[1])
	{
		free(lineptr);
		free(arg);
		exit(_exit);
	}
	exit_status = _atoi(arg[1]);
	free(lineptr);
	free(arg);
	exit(exit_status);
}

/**
 *print_env - Built-in to enviroment
 *@env: Enviroment
 *Return: 0
 */

void _getenv(char *env)
{
	size_t run = 0;

	while (env[run])
	{
		write(STDOUT_FILENO, env[run], _strlen(env[run]));
		write(STDOUT_FILENO, "\n", 1);
		run++;
	}
}
