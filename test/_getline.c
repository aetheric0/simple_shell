#include "../main.h"

/**
 * _getline - reads a line from stdin and stores it
 **/

ssize_t _getline(char **lineptr, size_t n, FILE *stream)
{
	ssize_t i = 0;
	int size = 80;
	char *buffer;
	int c;

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

int main(void)
{
	FILE *stream = stdin;
	ssize_t no;
	size_t n = 0;
	char *lineptr = NULL;

	no = _getline(&lineptr, n, stream);
	printf("%s", lineptr);
	return (0);
}
