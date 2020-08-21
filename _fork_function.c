#include "shell.h"
/**
 * _fork_fun - function that create a fork
 *@user_command: command and values path
 *@av: Has the name of our program
 *@env: environment
 *@getcommand: command line for the user
 *@pathValue: id of proces
 *@n: Checker add new test
 *Return: 0 success
 */

int _fork_fun(char **user_command, char **av, char **env, char *getcommand, int pathValue, int n)
{
	pid_t child;
	int status;
	char *format = "%s: %d: %s: not found\n";

	child = fork();

	if (child == 0)
	{
		if (execve(user_command[0], user_command, env) == -1)
		{
			fprintf(stderr, format, av[0], pathValue, user_command[0]);
			if (!n)
				free(user_command[0]);
			free(user_command);
			free(getcommand);
			exit(errno);
		}
	}
	else
	{
		wait(&status);

		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			return (WEXITSTATUS(status));
	}
	return (0);
}
