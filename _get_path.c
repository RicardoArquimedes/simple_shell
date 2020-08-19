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
	char *path_rela;

	char **path_absol = malloc((sizeof(char *) * size));
	char *copyPath = malloc((sizeof(char) * 300));

	if (copyPath == NULL || path_absol == NULL)
	{
		free(path_absol);
		free(copyPath);
		exit(EXIT_FAILURE);
	}

	copyPath = strcpy(copyPath, path);

	path_rela = strtok(copyPath, symbol);
	while (path_rela)
	{
		path_absol[index] = path_rela;
		index++;
		path_rela = strtok(NULL, symbol);
	}
	path_absol[index] = NULL;
	free(copyPath);
	return (path_absol);
}
