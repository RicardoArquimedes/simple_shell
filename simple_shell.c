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
	char *user_command[10], *token, *lineptr = NULL;
	size_t i, n;
	int status, value = 0;
	char *pathValue;
	char *getcommand = NULL;
	char **allValuesPath;
	int y = 0, len = 0;
	//signal(SIGINT, signal_handler);

	pathValue = _getenv("PATH"); /*busca el valor de la var env PATH*/

	while (1)
	{
		getcommand = "";

		allValuesPath = get_path(pathValue); /*todos los valores del PATH*/

		write(STDOUT_FILENO, "#cisfun$ ", 10);

		if (getline(&lineptr, &n, stdin) == -1)
			break;
		token = strtok(lineptr, " \t\n\r");
		for (i = 0; i < 10 && token != NULL; i++)
		{
			user_command[i] = token;
			token = strtok(NULL, " \t\n\r");
		}
		user_command[i] = NULL;

		if (stat(user_command[0], &st) == 0)
			getcommand = user_command[0];
		else
		{
			while (allValuesPath[value] != NULL)
			{
				len = strlen(allValuesPath[value]);

				if (allValuesPath[value][len - 1] != 47)
				{
					allValuesPath[value] = strcat(allValuesPath[value], "/");
				}

				getcommand = strcat(allValuesPath[value], user_command[0]);
				if (stat(getcommand, &st) == 0)
				{
					printf("el final command es %s\n", getcommand);
					free(allValuesPath);
					break;
				}
				//free(getcommand);
				value++;
				getcommand = NULL;
			}
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
	putchar('\n');
	free(lineptr);
	exit(status);
}