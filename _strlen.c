#include "shell.h"

/**
<<<<<<< HEAD
 * _strlen - return string.
 * @s: pointer
 * Return: 0
=======
 * _strlen - copies the string pointed to by src into dest
 * @s: A pointer
 * Return: char pointer to dest
>>>>>>> b4c33f1f956a4338558049462e4ef7630fdd6346
 */

int _strlen(char *s)
{
	int ch = 0;

	while (*(s + ch) != '\0')
	{
		ch++;
	}

	return (ch);
<<<<<<< HEAD
}
=======
}
>>>>>>> b4c33f1f956a4338558049462e4ef7630fdd6346
