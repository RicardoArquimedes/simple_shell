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
	char **copyAllvaluesPath = malloc((sizeof(char *) * 100));

	if (copyAllvaluesPath == NULL)
	{
		free(copyAllvaluesPath);
		exit(EXIT_FAILURE);
	}
	while (allValuesPath[value] != NULL)
	{
		char *pathValue = allValuesPath[value];

		copyAllvaluesPath[value] = malloc((sizeof(char *) * 100));
		if (copyAllvaluesPath[value] == NULL)
		{
			free(copyAllvaluesPath);
			exit(EXIT_FAILURE);
		}
		copyAllvaluesPath[value] = strcpy(copyAllvaluesPath[value], pathValue);
		value++;
	}
	value = 0;
	while (copyAllvaluesPath[value] != NULL)
	{
		len = _strlen(allValuesPath[value] + 1);
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
