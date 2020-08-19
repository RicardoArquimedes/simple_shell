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

int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _values_path(char **arg, char **env);
char *_get_command(char **allValuesPath, char *user_command);
void _getenv(char *env);
char **_get_token(char *lineptr);
int _putchar(char c);
size_t _strncmp(char *s1, char *s2, size_t n);
char *_strcat(char *dest, char *src);
void exit_command(char **args, char *lineptr, int _exit);
int _atoi(char *s);
int _fork_function(char **arg, char **av, char **env, char *lineptr, int np, int c);

#endif /* SHELL_H */
