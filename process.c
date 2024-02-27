#include "main.h"

/**
 * process - checks if argument is directory and replaces the shell process
 * with a program using execve
 * @ptr: array of pointers to strings holding command and arguments from
 * getline
 * @st: checks the PATH variable
 **/

void process(char **ptr, struct stat st)
{
	char *env[] = {"PATH:/bin", NULL};

	if (S_ISDIR(st.st_mode))
	{
		if (chdir(ptr[0]) == -1)
		{
			perror("./hsh");
			free(ptr);
			exit(EXIT_FAILURE);
		}
	}

	else
	{
		if ((execve(ptr[0], ptr, env)) == -1)
		{
			perror("./hsh");
		}
	}
}
