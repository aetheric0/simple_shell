#include "main.h"

/**
 * _shell_loop - loops the shell for interactive shell
 **/

void _shell_loop(void)
{
	pid_t my_pid;
	int wstatus;
	char **ptr = NULL;
	char *const env[] = {"PATH=/bin", NULL};

	do {
		my_pid = fork();
		if (my_pid == 0)
		{
			ptr = _tokens();
			if ((execve(ptr[0], ptr, env)) == -1)
				perror("./hsh");
		}

	} while (waitpid(my_pid, &wstatus, WUNTRACED));

	free(ptr);
}
