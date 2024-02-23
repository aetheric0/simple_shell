#include "main.h"

/**
 * main - executes an interactive or non-interactive shell if command is piped.
 * @argc: argument count for non-interactive shell
 * @argv: argument vector for non-interactive shell
 * Return: 0 (Success!)
 **/

int main(int argc, char *argv[])
{
	pid_t my_pid;
	/* int wstatus; */
	char *const env[] = {"PATH=/bin", NULL};

	/* Interactive Shell */
	if (argc == 1)
	{
		_shell_loop();
	}

	/* Non-Interactive Mode */
	else
	{
		my_pid = fork();
		if (my_pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
				perror("./hsh");
		}
		exit(EXIT_SUCCESS);
	}

	return (0);
}
