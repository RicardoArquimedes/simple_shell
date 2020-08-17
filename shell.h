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
unsigned int _strlen(const char *s);
char *_strcpy(char *dest, char *src);
char **get_path(char *path);

#endif /* SHELL_H */
