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
	int _terminal = 0;

	_terminal = isatty(fileno(stream));

	if (_terminal)
		write(STDOUT_FILENO, "$ ", 2);
	if (getline(&lineptr, &n, stream) == -1)
	{
		free(lineptr);
		exit(EXIT_SUCCESS);
	}
	lineptr[strcspn(lineptr, "\n")] = '\0';
	if (strcmp(lineptr, "env") == 0 || strcmp(lineptr, "printenv") == 0)
		printenv(env);
	if (strcmp(lineptr, "exit") == 0)
	{
		free(lineptr);
		exit(EXIT_SUCCESS);
	}
	return (lineptr);
}

/**
 * sigint_handler - frees memory when SIGINT is received
 * @signum: num for signal interruption
 **/

void sigint_handler(int signum)
{
	exit(signum);
}

/**
 * my_getline - reads a line from stdin and stores it
 * @lineptr: stores input
 * @n: set to 0
 * @stream: input stream
 * Return: number of chars read on success
 **/

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
        ssize_t i = 0;
        int size = 80;
        char *buffer;
        int c;

	if (n == NULL || stream == NULL)
	{
		;
	}
        buffer = (char *)malloc(sizeof(char) * size);
        if (buffer == NULL)
        {
                perror("malloc");
                return (-1);
        }

        c = getchar();
        while (c != EOF && c != '\n')
        {
                buffer[i] = c;
                i++;
                if (i >= size)
                {
                        size += size;
                        buffer = realloc(buffer, size);
                        if (buffer == NULL)
                        {
                                perror("./hsh");
                                return(-1);
                        }
                }
                c = getchar();
        }
        buffer[i] = '\0';

        *lineptr = buffer;
        if(*lineptr == NULL)
        {
                perror("./hsh");
                free(buffer);
                return (-1);
        }

        return (i);
}
