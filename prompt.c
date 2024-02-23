#include "main.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * _prompt - prints $ and waits for user input
 * Return: 0 (Success!), -1 on failure
 **/

char *_prompt(void)
{
	ssize_t text_size;
	FILE *stream = stdin;
	char *lineptr = NULL;
	size_t n = 0;

	printf("$ ");
	text_size = getline(&lineptr, &n, stream);
	if (text_size == -1)
	{
		return (NULL);
		perror("./hsh");
	}

	lineptr[strcspn(lineptr, "\n")] = '\0';

	return(lineptr);

}
