#include "main.h"

/**
 * _shell_loop - loops the shell for interactive shell
 **/

void _shell_loop(void)
{
	pid_t my_pid;
	int wstatus;
	struct stat st;
	char **ptr = NULL;
	char *const env[] = {"PATH=/bin", NULL};

	do {
		ptr = _tokens();
		if (stat(ptr[0], &st) == 0)
		{
			my_pid = fork();
			if (my_pid == 0)
			{
				if (S_ISDIR(st.st_mode))
				{
					if (chdir(ptr[0]) == -1)
					{
						perror("./hsh");
						exit(EXIT_FAILURE);
					}
				}
				else
				{
				     if ((execve(ptr[0], ptr, env)) == -1)
					     perror("./hsh");
				}
			}
		}
		else
		{
			perror("stat");
		}

		free(ptr);

	} while (waitpid(my_pid, &wstatus, WUNTRACED));

}
