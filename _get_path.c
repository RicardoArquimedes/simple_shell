#include "shell.h"
/**
 * _get_path - separate the path in new strings.
 * @path: absolute and relative of directories
 * Return:  a pointer to strings.
 */
char **_get_path(char *path)
{
	int index = 0, size = 100;
	char *symbol = ":";
	char **path_absol = malloc(size);
	char *path_rela;
	char *copyPath = malloc(_strlen(path) + 1);

	copyPath = strcpy(copyPath, path);

	if (path_absol == NULL)
		exit(EXIT_FAILURE);
	path_rela = strtok(copyPath, symbol);
	while (path_rela)
	{
		path_absol[index] = path_rela;
		index++;
		path_rela = strtok(NULL, symbol);
	}
	path_absol[index] = NULL;
	return (path_absol);
}
