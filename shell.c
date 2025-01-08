#include "shell.h"

/**
 * interactive_shell - Handles the interactive shell mode
 * @argv: Argument vector
 * @env: Environment variables
 */
void interactive_shell(char **argv, char **env)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char **args;

	while (1)
	{
		write(STDOUT_FILENO, "($) ", 4);
		nread = getline(&line, &len, stdin);
		if (nread == -1)
			break;

		line[nread - 1] = '\0'; /* Remove newline character */
		args = parse_line(line);
		if (args && args[0])
		{
			if (_strcmp(args[0], "exit") == 0)
				break;
			execute_command(args, argv, env);
		}
		free(args);
	}
	free(line);
}

/**
 * non_interactive_shell - Handles the non-interactive shell mode
 * @argv: Argument vector
 * @env: Environment variables
 */
void non_interactive_shell(char **argv, char **env)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char **args;

	nread = getline(&line, &len, stdin);
	if (nread != -1)
	{
		line[nread - 1] = '\0'; /* Remove newline character */
		args = parse_line(line);
		if (args && args[0])
			execute_command(args, argv, env);
		free(args);
	}
	free(line);
}
