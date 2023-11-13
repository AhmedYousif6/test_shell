#include "main.h"

/**
 * main - function that run the program.
 * @argc: number of argument.
 * @argv: argument.
 * Return: Always 0;
 */

int main(int argc, char **argv)
{
	char *cmd;
	char *deli = " \n\t";
	char **args;

	(void)argc;
	(void)argv;
	while (1)
	{
		prompt();
		signal(SIGINT, handle_sigint);
		cmd = read_line();
		args = tokenizer(cmd, deli);
		exec(args);
	}
	free_array(args);
	return (0);
}

void prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$$ ", 3);
	}
}

/**
 * handle_sigint - handle ctrl + c signal.
 * @sig: the signal.
 * Return: nothing.
 */

void handle_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, "$$ ", 3);
}

void free_array(char **args)
{
	size_t i;

	if (args == NULL)
	{
		return;
	}

	while (args[i])
	{
		free(args[i]);
		i++;
	}

	if (args[i] == NULL)
	{
		free(args[i]);
	}
	free(args);
}
