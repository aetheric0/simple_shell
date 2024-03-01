#include "main.h"

/**
 * process - checks if argument is directory and replaces the shell process
 * with a program using execve
 * @ptr: array of pointers to strings holding command and arguments from
 * getline
 * @st: checks the PATH variable
 **/

void process(char *reg_command, struct stat st, char **ptr)
{
	if (S_ISDIR(st.st_mode))
	{
		if (chdir(ptr[0]) == -1)
		{
			perror("./hsh");
			free(reg_command);
			free(ptr);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (execve(reg_command, ptr, NULL) == -1)
		{
			perror("./hsh");
			free(reg_command);
			free(ptr);
			exit(EXIT_FAILURE);
		}
	}
	free(reg_command);
}
