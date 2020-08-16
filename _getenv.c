#include "shell.h"
/**
 * _getenv - function to get the PATH env
 * @name: enviroment
 * Return:  the PATH in a string.
 */

char *_getenv(char *name)
{
	char **env, *value = NULL, *pathname = "PATH";
	int i;

	env = environ;
	for (i = 0; env[i]; i++)
	{
		pathname = strtok(env[i], "=");
		if (_strcmp(name, pathname) == 0)
		{
			value = strtok(NULL, env[i]);
			break;
		}
	}
	return (value);
}
