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

	signal(SIGINT, handle_sigint);
	(void)argc;
	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			write(STDOUT_FILENO, "$$ ", 3);
			cmd = read_line();
			args = tokenizer(cmd, deli);
			exec(args);
			free(args);
		}
	}

	else
	{
		cmd = argv[1];
		args = tokenizer(cmd, deli);
		exec(args);
		free(args);
	}
	return (0);
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
