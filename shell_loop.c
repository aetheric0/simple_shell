#include "main.h"

/**
 * _shell_loop - loops the shell for interactive shell
 * @env: shell env macro
 **/

void _shell_loop(char **env)
{
	pid_t my_pid;
	int wstatus;
	struct stat st;
	char **ptr = NULL;

	do {
		ptr = _tokens(env);
		if (stat(ptr[0], &st) == 0)
		{
			my_pid = fork();
			if (my_pid == -1)
			{
				_free(ptr);
				exit(EXIT_FAILURE);
			}
			else if (my_pid == 0)
				process(ptr, st);
		}
		else
		{
			if (_strcmp(ptr[0], "env") == 0
			    || _strcmp(ptr[0], "printenv") == 0)
			{
				continue;
			}
			perror("./hsh");
		}

		_free(ptr);

	} while (waitpid(my_pid, &wstatus, WUNTRACED));

	_free(ptr);
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
}
