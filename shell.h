#ifndef SHELL_H
#define SHELL_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/errno.h>

extern char **environ;
extern char *program_invocation_name;

char *_getenv(char *name);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _values_path(char **arg, char **env);
char *_get_command(char **allValuesPath, char *user_command);
char **_get_token(char *lineptr);
int _putchar(char c);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strcat(char *dest, char *src);
void exit_command(char **args);
int _atoi(char *s);
void _fork_function(char *getcommand, char **user_command, char *envp[]);

#endif /* SHELL_H */
