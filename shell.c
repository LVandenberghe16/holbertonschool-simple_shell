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
	int last_status = 0;

	while (1)
	{
		write(STDOUT_FILENO, "($) ", 4);
		nread = getline(&line, &len, stdin);
		if (nread == -1) /* Handle Ctrl+D */
			break;

		line[nread - 1] = '\0'; /* Remove newline character */
		args = parse_line(line);
		if (args && args[0])
		{
			if (_strcmp(args[0], "exit") == 0)
			{
				exit_shell(args, last_status); /* Pass last_status to exit_shell */
			}
			else if (_strcmp(args[0], "env") == 0)
			{
				print_env(env);
			}
			else
			{
				last_status = execute_command(args, argv, env);
			}
		}
		free(args);
	}
	free(line);
	exit(last_status); /* Exit with last executed command status */
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
	int last_status = 0;

	nread = getline(&line, &len, stdin);
	if (nread != -1)
	{
		line[nread - 1] = '\0'; /* Remove newline character */
		args = parse_line(line);
		if (args && args[0])
		{
			if (_strcmp(args[0], "exit") == 0)
			{
				exit_shell(args, last_status); /* Pass last_status to exit_shell */
			}
			else if (_strcmp(args[0], "env") == 0)
			{
				print_env(env);
			}
			else
			{
				last_status = execute_command(args, argv, env);
			}
		}
		free(args);
	}
	free(line);
	exit(last_status); /* Exit with last executed command status */
}
