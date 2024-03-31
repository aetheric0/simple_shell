#ifndef HEADER_FILE
#define HEADER_FILE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <limits.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

char *_prompt(char **);
void _shell_loop(char **);
char **_tokens(char **);
void printenv(char **);
void process(char *, struct stat, char **);
void _free(char **);
void sigint_handler(int);
void null_checker(char *);
char **_handle_path(char **);
ssize_t my_getline(char **, size_t *, FILE *);

/* String handlers */
int _strlen(char *);
int _strcmp(char *, char *);
int _strcspsn(char *, char);

#endif
