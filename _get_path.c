#include "shell.h"
/**
 * _get_path - get variable PATH.
 * @env: enviromente local
 * Return: value of PATH.
 */

char *_get_path(char **env)
{
	size_t index, var, count = 0;
	char *path = NULL;

	index = 0;
	while (_strncmp(env[index], "PATH=", 5))
		index++;

	if (env[index] == NULL)
		return (NULL);

	var = 5;
	while (env[index][var])
		var++, count++;

	path = malloc(sizeof(char) * (count + 1));
	if (path == NULL)
		return (NULL);

	for (var = 5, count = 0; env[index][var]; var++, count++)
		path[count] = env[index][var];

	path[count] = '\0';
	return (path);
}
