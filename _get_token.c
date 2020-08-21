#include "shell.h"
/**
 * _get_token - get token of string
 * @getcommand: comman user
 * Return: To a pointer
 */

char **_get_token(char *getcommand)
{
	char **user_command = NULL;
	char *token = NULL;
	size_t i = 0;
	int size = 0;

	if (getcommand == NULL)//si lo que obtiene getline es un NULL
		return (NULL);

	for (i = 0; getcommand[i]; i++)//se cuentan las palabras obtenidas de getline por espacios eje:"hola soy joss y ricardo" total  palabras
	{
		if (getcommand[i] == ' ')
			size++;//palabras totales
	}
	if ((size + 1) == _strlen(getcommand))//verifica que si escribio algo y no fue solo un enter
		return (NULL);
	user_command = malloc(sizeof(char *) * (size + 2));//solicito memoria a las palabras
	if (user_command == NULL)
		return (NULL);

	token = strtok(getcommand, " \n\t\r");//organizo las palabras quitando enter
	for (i = 0; token != NULL; i++)
	{
		user_command[i] = token;
		token = strtok(NULL, " \n\t\r");//quita espacios
	}
	user_command[i] = NULL;
	return (user_command);//retorna a main apalbra tokenizada
}
