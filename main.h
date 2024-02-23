#ifndef HEADER_FILE
#define HEADER_FILE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>

char *_prompt(void);
void _shell_loop(void);
char **_tokens(void);

#endif
