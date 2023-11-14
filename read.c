#include "main.h"

/**
 * read_line - function to read the user input (commands and arguments).
 * Return: user input (commands and arguments).
 */

char *read_line(void)
{
	char *cmd = NULL;
	size_t cmd_size = 0;
	ssize_t byte_read;

	byte_read = getline(&cmd, &cmd_size, stdin);
	if (byte_read == -1)
	{
		free(cmd);
		if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_SUCCESS);
	}
	else
	{
		if (cmd[byte_read - 1] == '\n')
		{
			cmd[byte_read - 1] = '\0';
		}
		return (cmd);
	}
}
