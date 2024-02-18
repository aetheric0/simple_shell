#include "main.h"

/**
 * main - executes a shell
 **/

int main(int argc, char *argv[])
{
	pid_t my_pid;
	char *const env[] = {"PATH=/bin", NULL};

	if (argc == 1)
	{
		_shell_loop();
	}
	else
	{
		my_pid = fork();
		if (my_pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
				perror("./hsh");
		}
	}

	return (0);
}
