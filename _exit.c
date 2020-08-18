#include "shell.h"

/**
 * exit_command - this function closes the prompt when the exit cmd is passed
 * @args: Pointer with the direction to free  the allocated memory for
 * the  arguments passed to the program.
 * Return: None
 */
void exit_command(char **args)
{
	int exit_status = 0, len1 = 0, len2 = 0;

	if (args[1] == NULL)
	{
		free(*args);
		exit(EXIT_SUCCESS);
	}

	exit_status = _atoi(args[1]);
	if (exit_status == -1)
	{
		len1 = _strlen(program_invocation_name);
		len2 = _strlen(": 1: exit: Illegal number: ");
		write(STDERR_FILENO, program_invocation_name, len1);
		write(STDERR_FILENO, ": 1: exit: Illegal number: ", len2);
		write(STDERR_FILENO, args[1], _strlen(args[1]));
		write(STDERR_FILENO, "\n", 1);
	}
	else
	{
		free(*args);
		exit(exit_status);
	}
}
