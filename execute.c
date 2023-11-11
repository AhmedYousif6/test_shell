#include "main.h"

/**
 * exec - function to execute commands with arguments.
 * @args: the commands and arguments to execute.
 * Return: nothing.
 */

void exec(char **args)
{
	int status = 0;
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("Error fork");
		free(args);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("Error execute");
			free(args);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}
