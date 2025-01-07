#include "shell.h"

/**
 * execute_command - Executes a command
 * @args: Command arguments
 * @argv: Argument vector
 * @env: Environment variables
 */
void execute_command(char **args, char **argv, char **env)
{
	char *cmd = resolve_path(args[0]);

	if (!cmd)
	{
		write(STDERR_FILENO, argv[0], strlen(argv[0]));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, args[0], strlen(args[0]));
		write(STDERR_FILENO, ": command not found\n", 20);
		return;
	}

	if (fork() == 0)
	{
		if (execve(cmd, args, env) == -1)
		{
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
	}

	wait(NULL);
	free(cmd);
}
