#include "main.h"

/**
 * main - executes a shell
 **/

int main()
{
	pid_t my_pid;
	char *ptr = "initializer";
	char *const env[] = {"PATH=/bin", NULL};
	char *const args[] = {NULL};

	do
	{
		ptr = _prompt();
		my_pid = fork();
		if (my_pid == 0)
		{
			if (execve(ptr, args, env) == -1)
			{
				perror("hsh");
				exit(EXIT_FAILURE);
			}
			else if (my_pid < 0)
				perror("forking failed");
		}
	}while (strcmp(ptr, "exit"));

	free(ptr);

	return (0);
}
