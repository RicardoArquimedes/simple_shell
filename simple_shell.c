#include "shell.h"
/**
 * main - main arguments functions
 * @argc: argumnents
 * @argv: arguments
 * @envp: environment
 * Return: Always Success 0
 */
int main(int argc __attribute__((unused)),
	 char *argv[] __attribute__((unused)), char *envp[])
{
	struct stat st;
	char *pathValue, *getcommand, *lineptr = NULL;
	size_t n;
	char **allValuesPath, **user_command;
	int get = 0;


	pathValue = _getenv("PATH");	      /*busca el valor de la var env PATH*/
	allValuesPath = _get_path(pathValue); /*todos los valores del PATH*/
	while (1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 10);
		get = getline(&lineptr, &n, stdin);
		if (get == EOF)
			break;
		user_command = _get_token(lineptr);
		if (strcmp(user_command[0], "exit") == 0)
			exit_command(user_command);
		if (stat(user_command[0], &st) == 0)
			getcommand = user_command[0];
		else
		{
			getcommand = _get_command(allValuesPath, user_command[0]);
			if (getcommand == NULL)
			{
				free(getcommand);
				perror("Command not found"); /*liberar memoria pendiente de revisar*/
			}
		}
		_fork_function(getcommand, user_command, envp);
	}
	free(allValuesPath);
	putchar('\n');
	return (0);
}
