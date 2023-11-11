#include "main.h"
/**
 * tokenizer - function to parse string into tokens.
 * @str: string to parse.
 * @deli: delimiters.
 * Return: tokens from the string (commands and arguments).
 */
char **tokenizer(char *str, char *deli)
{
	char *cpy_str = NULL, *token;
	char **toks;
	int count = 0, i, x;

	cpy_str = malloc(sizeof(char) * strlen(str) + 1);
	if (cpy_str == NULL)
	{
		perror("Error allocate memory");
		free(str);
		exit(EXIT_FAILURE);
	}
	strcpy(cpy_str, str);
	token = strtok(str, deli);
	while (token)
		count++;
	token = strtok(NULL, deli);
	toks = malloc(sizeof(char *) * count + 1);
	if (toks == NULL)
	{
		perror("Error allocate memory");
		free(str), free(cpy_str), exit(EXIT_FAILURE);
	}
	token = strtok(cpy_str, deli);
	for (i = 0; token != NULL; i++)
	{
		toks[i] = malloc(sizeof(char) * strlen(token) + 1);
		if (toks[i] == NULL)
		{
			perror("Error allocate memory");
			for (x = 0; toks[x] != NULL; x++)
				free(toks[x]);
			free(str), free(cpy_str), exit(EXIT_FAILURE);
		}
		strcpy(toks[i], token);
		token = strtok(NULL, deli);
	}
	toks[i] = NULL, free(str), free(cpy_str);
	return (toks);
}