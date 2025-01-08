#include "shell.h"

/**
 * exit_shell - Exits the shell program
 * @args: Array of command arguments
 */
void exit_shell(char **args)
{
	int status = 0;

	if (args[1])
	{
		status = atoi(args[1]);
		if (status < 0)
		{
			write(STDERR_FILENO, "exit: Invalid status\n", 21);
			status = 0;
		}
	}

	exit(status);
}

/**
 * print_env - Prints the current environment variables
 * @env: Environment variables
 */
void print_env(char **env)
{
	int i = 0;

	while (env[i])
	{
		write(STDOUT_FILENO, env[i], strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
