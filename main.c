#include "main.h"

/**
 * main - executes an interactive or non-interactive shell if command is piped.
 * @ac: argument count for non-interactive shell
 * @av: argument vector for non-interactive shell
 * @env: shell environment macro
 * Return: 0 (Success!)
 **/

int main(int ac, char **av, char **env)
{
	ac = 0;
	if (av != NULL)
		av++;
	ac++;
	signal(SIGINT, sigint_handler);
	_shell_loop(env);

	return (0);
}

/**
 * printenv - prints shell environment variable
 * @env: shell environment macro
 **/

void printenv(char **env)
{
	int i = 0;

	for (i = 0; env[i] != NULL; i++)
	printf("%s\n", env[i]);

}
