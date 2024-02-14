#include "main.h"

/**
 * main - executes a shell
 **/

int main()
{
	pid_t my_pid;
	char *ptr;

	my_pid = fork();
	ptr = _prompt();
	if (ptr == NULL)
		printf("failed to read command");

	return (0);
}
