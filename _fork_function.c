#include "shell.h"
/**
 * _fork_function - function that create a fork
 * @getcommand: matrix of command and argument
 * @user_command: matrix of command and argument
 * @envp: matrix of command and argument
 *
 */

void _fork_function(char *getcommand, char **user_command, char *envp[])
{
	pid_t child;
	int status;

	child = fork();
	if (child == 0)
	{
		if (execve(getcommand, user_command, envp))
		{
			perror("./hsh");
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);
}
