#include "shell.h"
/**
 * _get_command - get path
 * @allValuesPath: value paths
 * @user_command: comman user
 */

char *_get_command(char **allValuesPath, char *user_command)
{
	struct stat st;
	int value = 0, len = 0;

	char *getcommand = malloc(200);
	char **copyAllvaluesPath = malloc(100);

	while (allValuesPath[value] != NULL)
	{
		char *pathValue = allValuesPath[value];

		copyAllvaluesPath[value] = malloc((sizeof(char *) * 100));
		copyAllvaluesPath[value] = strcpy(copyAllvaluesPath[value], pathValue);
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
		printf("el path es: %s\n", copyAllvaluesPath[value]);

		getcommand = strcat(copyAllvaluesPath[value], user_command);
		if (stat(getcommand, &st) == 0)
		{
			printf(" %s\n", "llegue4");
			printf("el final command es %s\n", getcommand);
			free(copyAllvaluesPath);
			return (getcommand);
		}
		free(getcommand);
		getcommand = NULL;
		value++;
	}
	return (getcommand);
}
