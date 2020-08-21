#include "shell.h"
/**
 * _exit_command - this function closes the simple_shell when
 * @user_command: pointer with the direction argument.
 * @get_command: standar input string
 * @_exit: value of exit
 * Return: None
 */
void _exit_command(char **user_command, char *getcommand, int _exit)
{
	int exit_status = 0;

	if (!user_command[1])//si es exit y un null
	{
		free(getcommand);
		free(user_command);
		exit(_exit);
	}
	exit_status = atoi(user_command[1]);//convierte char en int para salida shell
	free(getcommand);
	free(user_command);
	exit(exit_status);//es 0
}

/**
 *_getenv - function to get all env
 *@env: enviroment
 *Return: 0
 */

void _getenv(char **env)
{
	size_t run = 0;

	while (env[run])
	{
		write(STDOUT_FILENO, env[run], _strlen(env[run]));//print environt
		write(STDOUT_FILENO, "\n", 1);//enter en cada environt
		run++;//avanza posicion
	}
}
