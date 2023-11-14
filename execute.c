#include "main.h"

/**
 * exec - function to execute commands with arguments.
 * @args: the commands and arguments to execute.
 * Return: nothing.
 */

void exec(char **args)
{
	int status = 0;
	char *command = NULL, *cmd = NULL;
	pid_t pid = fork();
	char *cmmd;

	if (pid < 0)
	{
		perror("simple_shell");
		free_array(args);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (args[0])
		{
			{
				write(STDERR_FILENO, "simple_shell", 12);
				write(STDERR_FILENO, ": ", 2);
				write(STDERR_FILENO, "1", 1);
				write(STDERR_FILENO, ": ", 2);
				write(STDERR_FILENO, args[0], strlen(args[0]));
				write(STDERR_FILENO, ": not found\n", 12);
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
<<<<<<< HEAD

void print_env(void)
{
	unsigned int i = 0;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
=======
>>>>>>> 5203c61882305053192428b7fce3ef1fc957a9a0
