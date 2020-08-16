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
	/*struct stat st;*/
	pid_t child;
	char *user_command[10], *token, *lineptr = NULL;
	size_t i, n;
	int status, value = 0;
	char *pathValue, *getcommand;
	char **allValuesPath;
	
	signal(SIGINT, signal_handler);
	while (1)
	{
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
		pathValue = _getenv("PATH");/*busca el valor de la var env PATH*/
		allValuesPath = get_path(pathValue);/*todos los valor del PATH*/

		while (allValuesPath[value] != NULL )
		{
			getcommand = strcat(allValuesPath[value], user_command[0]);
			/*if(stat(getcommand,&st) == 0)
			{
				free(allValuesPath);
				break;
			}*/
			free(getcommand);
			value++;
		}
		if (getcommand == NULL)
		{
			perror("Command not found");/*liberar memoria pendiente de revisar*/
			exit(EXIT_FAILURE);
		}
	

		child = fork();
		if (child == 0)
		{
			if (execve(getcommand,user_command, envp))
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