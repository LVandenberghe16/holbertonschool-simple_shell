#include "shell.h"

/**
 * parse_line - Splits a line into an array of arguments
 * @line: Input line
 *
 * Return: An array of arguments, or NULL on failure
 */
char **parse_line(char *line)
{
	char **args = malloc(sizeof(char *) * 64);
	char *token;
	size_t i = 0;

	if (!args)
		return (NULL);

	token = strtok(line, " ");
	while (token)
	{
		args[i++] = strdup(token);
		token = strtok(NULL, " ");
	}
	args[i] = NULL;

	return (args);
}

/**
 * _strcmp - Compares two strings
 * @s1: First string
 * @s2: Second string
 *
 * Return: Difference between the strings
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
