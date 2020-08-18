#include "shell.h"
/**
 * _getenv - function to get the PATH env
 * @name: enviroment
 * Return:  the PATH in a string.
 */

char *_getenv(char *name)
{
<<<<<<< HEAD
	char **env, *value = NULL, *pathname = "PATH";
	int i;
=======
	char *value = NULL, *pathname = "PATH";
	int len = 4;
	char **env;
>>>>>>> b4c33f1f956a4338558049462e4ef7630fdd6346

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
