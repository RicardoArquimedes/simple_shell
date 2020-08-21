#include "shell.h"
/**
 * _values_path - separate the path in new strings.
 * @user_command: command input of user.
 * @env: enviroment.
 * Return:  a pointer to strings.
 */
int _values_path(char **user_command, char **env)
{
	char *token = NULL, *path_rela = NULL, *path_absol = NULL;
	size_t value_path, command;
	struct stat stat_lineptr;

	if (stat(*user_command, &stat_lineptr) == 0)//si es /bin/ls
		return (-1);
	path_rela = _get_path(env);//var = value  ls, pwd otros sin path
	if (!path_rela)//si returna NULL
		return (-1);
	token = strtok(path_rela, ":");//separa cada :
	command = _strlen(*user_command);//largo de string type user
	while (token)
	{
		value_path = _strlen(token);//cuenta los  caracteres de c/string
		path_absol = malloc(sizeof(char) * (value_path + command + 2));
		if (!path_absol)
		{
			free(path_rela);//se solicito memoria en _get_path
			return (-1);
		}
		path_absol = _strcpy(path_absol, token);//se hace copia para poder concatenar
		_strcat(path_absol, "/");//concatemos / al final de c/string
		_strcat(path_absol, *user_command);//se concatena bin/ls (ejemplo)

		if (stat(path_absol, &stat_lineptr) == 0)//eso concatenado si es un ejecutable? /bin/ls?
		{
			*user_command = path_absol;
			free(path_rela);
			return (0);
		}
		free(path_absol);//en caso contrario libera memoria (/bin/lx)
		token = strtok(NULL, ":");//validamos siguiente string de path
	}
	free(path_rela);
	return (-1);
}
