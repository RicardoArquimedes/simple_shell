#include "shell.h"
/**
 * _getenv - function to get the PATH env
 * @name: enviroment
 * Return:  the PATH in a string.
 */

char *_getenv(char *name)
{
	char *value = NULL, *pathname = "PATH";
	int len = 4;
	char **env;

	env = environ;
	while (*env != NULL)
	{
		if (strncmp(*env, pathname, len) == 0)
		{
			value = (*env) + (len + 1);
			break;
		}
		env++;
	}
	return (value);
}
