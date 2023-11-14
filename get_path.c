#include "main.h"

/**
 * get_path - finds the path of a command
 * @cmmd: command 
 * 
 * Return: path of the command
*/
char *get_path(char *cmmd)
{
	char *path, *path_copy, *new_path;
	const char *deli = ":";
	char *path_tok;
	int len;
	struct stat st;

	path = getenv("PATH");
	path_copy = strdup(path);
	len = strlen(cmmd);

	path_tok = strtok(path_copy, deli);
	while (path_tok)
	{
		new_path = malloc(len + strlen(path) + 2);
		/*the 2 is for the "/" and "\0" that will be added*/
		if (new_path == NULL)
		{
			perror("Allocation fail");
			free(new_path);
			exit(EXIT_FAILURE);
		}
		/*start building the new path*/
		strcpy(new_path, path_tok);
		strcat(new_path, "/");
		strcat(new_path, cmmd);
		strcat(new_path, "\0");

		/*checking for path existence*/
		if (stat(new_path, &st) == 0)
		{
			free(path_copy);
			return (new_path);
		}
		else
		{
			free(new_path);
			path_tok = strtok(NULL, deli);
		}
	}
	free(path_copy);

	if (stat(cmmd, &st) == 0)
	{
		return (cmmd);
	}
	return (NULL);
}
