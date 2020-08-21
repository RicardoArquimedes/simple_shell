#include "shell.h"
/**
 * _get_path - get variable PATH.
 * @env: enviromente local
 * Return: value of PATH.
 */

char *_get_path(char **env)
{
	size_t index = 0, var = 0, count = 5;
	char *path = NULL;

	for (index = 0; _strncmp(env[index], "PATH=", 5); index++)//comparazcion de string usuaario y enveriont
		;
	if (env[index] == NULL)// en caso de no encontrar path en env
		return (NULL);

	for (count = 5; env[index][var]; var++, count++)//cuenta los char apartir de value.
		;
	path = malloc(sizeof(char) * (count + 1));//solicita memoria para el valor de path

	if (path == NULL)
		return (NULL);

	for (var = 5, count = 0; env[index][var]; var++, count++)
		path[count] = env[index][var];//se guarada pat

	path[count] = '\0';//se cierra string por buenas practicas
	return (path);//retorno chars de value.
}
