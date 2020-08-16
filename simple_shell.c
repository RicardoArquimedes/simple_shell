#include "shell.h"

/**
 * main - main arguments functions
 * @argc: argumnents
 * @argv: arguments
 * @envp: environment
 * Return: Always Success 0
 */

int main(int argc __attribute__((unused)), char *argv[] __attribute__((unused)), char *envp[])
{
	pid_t child;
	char *user_command[10], *token, *lineptr = NULL;
	size_t i, n;
	int status;

	while (1)
	{
		printf("#cisfun$ ");
		if (getline(&lineptr, &n, stdin) == -1)
			break;
		token = strtok(lineptr, " \t\n\r");
		for (i = 0; i < 10 && token != NULL; i++)
		{
			user_command[i] = token;
			token = strtok(NULL, " \t\n\r");
		}
		user_command[i] = NULL;
		child = fork();
		if (child == 0)
		{
			if (execve(user_command[0], user_command, envp))
			{
				perror("./simple_shell");
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(&status);
	}
	putchar('\n');
	free(lineptr);
	exit(status);
}
