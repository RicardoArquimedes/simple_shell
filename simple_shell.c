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
	struct stat st;
	pid_t child;
	char *token, *lineptr = NULL;
	size_t i, n;
	int status;
	char *pathValue, *getcommand;
	char **allValuesPath, **user_command;
	int y = 0;
	//signal(SIGINT, signal_handler);

	pathValue = _getenv("PATH");	      /*busca el valor de la var env PATH*/
	allValuesPath = _get_path(pathValue); /*todos los valores del PATH*/

	while (1)
	{
		printf(" %s\n", "INICIO");
		write(STDOUT_FILENO, "#cisfun$ ", 10);

		if (getline(&lineptr, &n, stdin) == -1)
			break;
		user_command = _get_token(lineptr);
		if (stat(user_command[0], &st) == 0)
		{
			printf("%s\n", "aca si");
			getcommand = user_command[0];
		}
		else
		{
			printf("%s\n", "aca else");
			getcommand = _get_command(allValuesPath, user_command[0]);
			if (getcommand == NULL)
			{
				perror("Command not found"); /*liberar memoria pendiente de revisar*/
							     //exit(EXIT_FAILURE);
			}
		}
		child = fork();
		if (child == 0)
		{
			if (execve(getcommand, user_command, envp))
			{
				perror("./simple_shell");
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(&status);
	}
	free(allValuesPath);
	putchar('\n');
	free(lineptr);
	exit(status);
}