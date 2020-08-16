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
char *_strcpy(char *dest, char *src);
void prompt(void);
int _strlen(char *s);
void signal_handler(int signal __attribute__((unused)));

#endif /* SHELL_H */
