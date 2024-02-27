#include "main.h"

/**
 * _tokens - stores each string separately in an
 * array by getting rid of delimiters
 * @env: environment macro
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
		null_checker(string);

	token = strtok(string, " ");
	while (token != NULL)
	{
		tokens[pos] = (char *)malloc(strlen(token) + 1);
		if (tokens[pos] == NULL)
			null_checker(tokens[pos]);
		strcpy(tokens[pos], token);
		pos++;
		token = strtok(NULL, " ");
	}
	tokens[pos] = NULL;
	free(string);
	return (tokens);
}

/**
 * null_checker - handles failed malloc call
 **/

void null_checker(char *s)
{
	perror("hsh");
	free(s);
	exit(EXIT_FAILURE);
}
