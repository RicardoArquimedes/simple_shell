#include "shell.h"
/**
 * main - main arguments functions
 * @ac:count of argumnents
 * @av: arguments
 * @env: environment
 * Return: _exit = 0.
 */
int main(int ac, char **av, char **env)//input usuario
{
	char *getcommand = NULL, **user_command = NULL;
	int pathValue = 0, _exit = 0, n = 0;
	(void)ac;

	while (1)//mantiene vivio el shell
	{
		getcommand = _getline_command();//print "$" y obtiene type usurario
		if (getcommand)
		{
			pathValue++;
			user_command = _get_token(getcommand);//obtenemos palabra tokenizada e lo que escribio usuario en consola
			if (!user_command)//si no escribio nada el usuario (enter)
			{
				free(getcommand);
				continue;
			}
			if (!_strcmp(user_command[0], "exit"))//user inserto "exit"?
				_exit_command(user_command, getcommand, _exit);//salida shell
			if (!_strcmp(user_command[0], "env"))//user inserto "env"?
				_getenv(env);//print environment
			else
			{
				n = _values_path(&user_command[0], env);
				_exit = _fork_fun(user_command, av, env, getcommand, pathValue, n);
				if (n == 0)
					free(user_command[0]);
			}
			free(user_command);
		}
		else//cunado getcommand no es valido siendo NULL/letras/
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(_exit);
		}
		free(getcommand);
	}
	return (_exit);
}
