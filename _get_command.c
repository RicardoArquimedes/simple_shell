#include "shell.h"
/**
 * _get_command - get coomand of user.
 * @allValuesPath: value paths
 * @user_command: comman user
 * Return: To a pointers
 */

char *_get_command(char **allValuesPath, char *user_command)
{
	struct stat st;
	int value = 0, len = 0;
	char *getcommand = NULL;
	char **copyAllvaluesPath = NULL;

	getcommand = malloc(200);
	copyAllvaluesPath = malloc(100);

	while (allValuesPath[value] != NULL)
	{
		char *pathValue = allValuesPath[value];

		copyAllvaluesPath[value] = malloc((sizeof(char *) * 100));
		copyAllvaluesPath[value] = _strcpy(copyAllvaluesPath[value], pathValue);
		value++;
	}
	value = 0;
	while (copyAllvaluesPath[value] != NULL)
	{
		len = _strlen(allValuesPath[value]);

		if (allValuesPath[value][len - 1] != 47)
		{
			copyAllvaluesPath[value] = strcat(copyAllvaluesPath[value], "/");
		}

		getcommand = strcat(copyAllvaluesPath[value], user_command);
		if (stat(getcommand, &st) == 0)
		{
			free(copyAllvaluesPath);
			return (getcommand);
		}
		free(getcommand);
		getcommand = NULL;
		value++;
	}
	return (getcommand);
}
