#include "main.h"

/**
 * main - executes a shell
 **/

int main(int argc, char *argv[])
{
	pid_t my_pid;
	int wstatus;
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
		waitpid(my_pid, &wstatus, 0);
	}

	return (0);
}
