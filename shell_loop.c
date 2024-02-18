#include "main.h"

/**
 * _shell_loop - loops the shell for interactive shell
 **/

void _shell_loop(void)
{
	pid_t my_pid;
	int wstatus;
	char *ptr = NULL;
	char *args[] = {NULL};
	char *const env[] = {"PATH=/bin", NULL};

	my_pid = fork();
	do
	{
		while (my_pid == 0)
		{
			ptr = _prompt();
			ptr[strcspn(ptr, "\n")] = '\0';
			if ((execve(ptr, args, env)) == -1)
				perror("./hsh");
		}
		waitpid(my_pid, &wstatus, WUNTRACED);
	}while (WIFEXITED(wstatus) && WIFSIGNALED(wstatus));

	free(ptr);
}
