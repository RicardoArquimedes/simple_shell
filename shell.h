#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/errno.h>

extern char **environ;

char *_getenv(char *name);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char **_get_path(char *path);
char *_get_command(char **allValuesPath, char *user_command);
char **_get_token(char *lineptr);
int _putchar(char c);

#endif /* SHELL_H */
