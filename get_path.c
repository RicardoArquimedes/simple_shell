#include "shell.h"
/**
 * get_path - separate the path in new strings.
 * @path: absolute and relative of directories
 * Return:  a pointer to strings.
 */
char **get_path(char *path)
{
	int index = 0, size = 100;
	char *symbol = ":";
	char **path_absol = malloc(size);
	char *path_rela;

	if (path_absol == NULL)
		exit(EXIT_FAILURE);
	path_rela = strtok(path, symbol);
	while (path_rela)
	{
		path_absol[index] = path_rela;
		index++;
		path_rela = strtok(NULL, symbol);
	}
	path_absol[index] = NULL;
	return (path_absol);
}
