#include "main.h"

char **_handle_path(char **env)
{
	char **command;
	char *path = NULL;
	char *token = NULL;
	size_t length, size;
	char *path_copy = NULL;
	char *reg_cmd_string = NULL;
	char full_path[1024] = "";

	command = _tokens(env);
	path = getenv("PATH");
	if (*command[0] == '/' || *command[0] == '.'
	    || *command[0] == '~')
	{
		if (access(*command, F_OK) == 0)
			return (command);
	}
		if (path == NULL)
			return NULL;
		length = _strlen(command[0]);
		path_copy = strdup(path);
		token = strtok(path_copy, ":");

		while (token != NULL)
		{
			size = _strlen(token);
			size++;
			if (size + length >= sizeof(full_path))
			{
				free(path_copy);
				return (NULL);
			}
			strcpy(full_path, token);
			strcat(full_path, "/");
			strcat(full_path, command[0]);

			if (access(full_path, F_OK) == 0)
			{
				free(path_copy);
				reg_cmd_string = strdup(full_path);
				free(command[0]);
				command[0] = NULL;
				command[0] = reg_cmd_string;
				return (command);
			}
			token = strtok(NULL, ":");
		}
		free(path_copy);
		free(command[0]);
		free(command);
		command = NULL;
		perror("./hsh");

		return (NULL);
}
