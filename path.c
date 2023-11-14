#include "main.h"

/***/

char *cmd_path(char *command)
{
	char *path, *path_cpy, *path_tok, *path_file;
	int command_len, dir_len;
	struct stat buf;

	path = getenv("PATH");

	if (path)
	{
		path_cpy = strdup(path);
		command_len = strlen(command);
		path_tok = strtok(path_cpy, ":");
		while (path_tok != NULL)
		{
			dir_len = strlen(path_tok);
			path_file = malloc(command_len + dir_len + 2);
			strcpy(path_file, path_tok);
			strcat(path_file, "/");
			strcat(path_file, command);
			strcat(path_file, "\0");
			if (stat(path_file, &buf) == 0)
			{
				free(path_cpy);
				return (path_file);
			}
			else
			{
				free(path_file);
				path_tok = strtok(NULL, ":");
			}
		}
		free(path_cpy);
		if (stat(command, &buf) == 0)
		{
			return (command);
		}
		return (NULL);
	}
	return (NULL);
}
