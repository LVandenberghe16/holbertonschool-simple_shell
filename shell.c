#include "shell.h"

/**
 * interactive_shell - Handles the interactive shell mode
 * @argv: Argument vector
 * @env: Environment variables
 */
void interactive_shell(char **argv, char **env)
{
	char *line = NULL, **args;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		write(STDOUT_FILENO, "($) ", 4);
		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			if (feof(stdin))
			{
				write(STDOUT_FILENO, "\n", 1);
				break;
			}
			perror("getline");
			break;
		}
		line[nread - 1] = '\0';
		args = parse_line(line);
		if (args && args[0])
		{
			if (_strcmp(args[0], "exit") == 0)
			{
				exit_shell(args);
				free(args);
				free(line);
			}
			else if (_strcmp(args[0], "env") == 0)
			{
				print_env(env);
			}
			else
			{
				execute_command(args, argv, env);
			}
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
	char *line = NULL, **args;
	size_t len = 0;
	ssize_t nread;

	nread = getline(&line, &len, stdin);
	if (nread != -1)
	{
		line[nread - 1] = '\0';
		args = parse_line(line);

		if (args && args[0])
		{
			if (_strcmp(args[0], "exit") == 0)
			{
				exit_shell(args);
				free(args);
				free(line);
			}
			else if (_strcmp(args[0], "env") == 0)
			{
				print_env(env);
			}
			else
			{
				execute_command(args, argv, env);
			}
		}
		free(args);
	}
	free(line);
}
