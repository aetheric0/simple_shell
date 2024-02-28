#include "main.h"

/**
 * _tokens - stores each string separately in an
 * array by getting rid of delimiters
 * Return: pointer to array of strings
 **/

char **_tokens(char **env)
{
	char *string = _prompt(env);
	int i = 0;
	char *token = NULL;
	char **tokens = NULL;
	int pos = 0;
	int string_count = 1;

	if (string[i] == '\0')
	{
		free(string);
		return (_tokens(env));
	}

	for (i = 0; string[i] != '\0'; i++)
	{
		if (string[i] == ' ')
			string_count++;
	}
	tokens = (char **)malloc(sizeof(char *) * (string_count + 1));
	if (tokens == NULL)
	{
		perror("hsh");
		free(string);
		exit(EXIT_FAILURE);
	}

	token = strtok(string, " ");
	while (token != NULL)
	{
		tokens[pos] = (char *)malloc(strlen(token) + 1);
		if (tokens[pos] == NULL)
		{
			perror("hsh");
			free(tokens[pos]);
			exit(EXIT_FAILURE);
		}
		strcpy(tokens[pos], token);
		pos++;
		token = strtok(NULL, " ");
	}
	tokens[pos] = NULL;
	free(string);
	return (tokens);
}
