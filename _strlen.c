#include "shell.h"

/**
 * _strlen - return string.
 * @s: pointer
 * Return: 0
 */

int _strlen(char *s)
{
	int ch = 0;

	while (*(s + ch) != '\0')
	{
		ch++;
	}

	return (ch);
}