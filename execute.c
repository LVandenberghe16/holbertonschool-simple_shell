#include "shell.h"

/**
 * execute_command - Executes a command
 * @args: Command arguments
 * @argv: Argument vector
 * @env: Environment variables
 */
void execute_command(char **args, char **argv, char **env)
{
	pid_t pid;
	int status;
	char *cmd_path;

	cmd_path = resolve_path(args[0]);
	if (!cmd_path)
	{
		fprintf(stderr, "%s: No such file or directory\n", argv[0]);
		return;
	}

	pid = fork();
	if (pid == 0)
	{
		execve(cmd_path, args, env);
		perror(argv[0]);
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
	}
	else
	{
		perror(argv[0]);
	}

	if (cmd_path != args[0])
		free(cmd_path);
}
