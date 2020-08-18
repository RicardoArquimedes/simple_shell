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
<<<<<<< HEAD
char *_strcpy(char *dest, char *src);
void prompt(void);
int _strlen(char *s);
void signal_handler(int signal __attribute__((unused)));
char **get_path(char *path);
ssize_t print_env(void);
int lsh_exit(char **args);
=======
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char **_get_path(char *path);
char *_get_command(char **allValuesPath, char *user_command);
char **_get_token(char *lineptr);
int _putchar(char c);
>>>>>>> b4c33f1f956a4338558049462e4ef7630fdd6346

#endif /* SHELL_H */
