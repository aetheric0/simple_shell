#include "main.h"

/**
 * _prompt - prints $ and waits for user input
 * @env: shell environment macro
 * Return: pointer to string from getline
 **/

char *_prompt(char **env)
{
	FILE *stream = stdin;
	char *lineptr = NULL;
	size_t n = 0;

	write(STDOUT_FILENO, "$ ", 2);
	if (getline(&lineptr, &n, stream) == -1)
	{
		free(lineptr);
		write(1, "\n", 1);
		exit(EXIT_SUCCESS);
	}
	lineptr[_strcspsn(lineptr, '\n')] = '\0';
	if (_strcmp(lineptr, "env") == 0 || _strcmp(lineptr, "printenv") == 0)
		printenv(env);
	if (_strcmp(lineptr, "exit") == 0)
		exit(EXIT_SUCCESS);
	return (lineptr);
}

/**
 * sigint_handler - frees memory when SIGINT is received
 * @signum: num for signal interruption
 **/

void sigint_handler(int signum)
{
	write(STDOUT_FILENO, "\n", 1);
	exit(EXIT_SUCCESS);
}
