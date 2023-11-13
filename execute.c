#include "main.h"

/**
 * exec - function to execute commands with arguments.
 * @args: the commands and arguments to execute.
 * Return: nothing.
 */

void exec(char **args)
{
	int status = 0;
	struct stat st;
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("Error fork");
		free_array(args);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (args[0])
		{
			if (stat(args[0], &st) == 0)
			{
				if (execve(args[0], args, environ) == -1)
				{
					perror("Error execute");
					free_array(args);
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				write(STDOUT_FILENO, "simple_shell", 12);
				write(STDOUT_FILENO, ": ", 2);
				write(STDOUT_FILENO, "1", 1);
				write(STDOUT_FILENO, ": ", 2);
				write(STDOUT_FILENO, args[0], strlen(args[0]));
				write(STDOUT_FILENO, ": not found\n", 12);
			}
		}
		free_array(args);
		exit(EXIT_SUCCESS);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}

