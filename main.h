#ifndef HEADER_FILE
#define HEADER_FILE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

char *_prompt(char **);
void _shell_loop(char **);
char **_tokens(char **);
void printenv(char **);
void process(char **, struct stat);
void _free(char **);
void sigint_handler(int);

#endif
