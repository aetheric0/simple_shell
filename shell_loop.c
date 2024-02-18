#include "main.h"

/**
 * _shell_loop - loops the shell for interactive shell
 **/

void _shell_loop(void)
{
	pid_t my_pid;
	char *ptr = "initializer";
	char *args[] = {NULL};
	char *const env[] = {"PATH=/bin", NULL};

	do
	{
		ptr = _prompt();
		ptr[strcspn(ptr, "\n")] = '\0';
		my_pid = fork();
		while (my_pid == 0)
		{
			if ((execve(ptr, args, env)) == -1)
				perror("./hsh");
		}
	} while((strcmp(ptr, "exit")) != 0);

	free(ptr);
}
