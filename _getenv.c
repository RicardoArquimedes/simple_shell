#include "shell.h"
/**
 * _getenv - function to get all env
 * @name: name enviroment
 * Return: the value of name.
 */

char *_getenv(char *name)
{
	char *value = NULL;
	int len = _strlen(name);
	char **env;

	env = environ;
	while (*env != NULL)
	{
		if (_strncmp(*env, name, len) == 0)
		{
			value = (*env) + (len + 1);
			break;
		}
		env++;
	}
	return (value);
}
