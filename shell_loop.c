#include "main.h"

/**
 * _shell_loop - loops the shell for interactive shell
 * @env: shell env macro
 **/

void _shell_loop(char **env)
{
	pid_t my_pid;
	int wstatus;
	char *reg_command = NULL;
	struct stat st;
	char **ptr = NULL;

	do {
		ptr = _handle_path(env);
		if (ptr == NULL)
		{
			free(ptr);
			_shell_loop(env);
		}
		reg_command = *ptr;
		if (stat(reg_command, &st) == 0)
		{
			my_pid = fork();
			if (my_pid == -1)
			{
				_free(ptr);
				exit(EXIT_FAILURE);
			}
			else if (my_pid == 0)
				process(ptr[0], st, ptr);
			_free(ptr);
			reg_command = NULL;
		}
		else
			perror("./hsh");

	} while (waitpid(my_pid, &wstatus, WUNTRACED));
}

/**
 * _free - frees blocks of dynamically allocated memory
 * both in inner and outer loop
 * @ptr: address to dynamically allocated memory
 **/

void _free(char **ptr)
{
	int i;

	for (i = 0; ptr[i] != NULL; i++)
		free(ptr[i]);
	free(ptr);
	ptr = NULL;
}
