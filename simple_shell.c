#include "shell.h"

/**
 * main - main arguments functions
 * @argc: arguments
 * @argv: arguments
 * @envp: environment
 * Return: 0 Always Success.
 */

int main(int argc, char *argv[], char *envp[])
{
	pid_t child;
	char *user_command[10], *token, *lineptr = NULL;

	while (1)
	{
		printf("$ ");
		if (getline(&lineptr, &n, stdin) == -1)
			break;
		token = strtok(lineptr, " \t\n\r");
		for (i = 0; i < 16 && token != NULL; i++)
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
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(&status);
	}
	putchar('\n');
	free(lineptr);
}
