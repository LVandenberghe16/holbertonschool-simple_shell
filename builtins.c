#include "shell.h"

/**
 * exit_shell - Exits the shell program
 * @args: Array of command arguments
 * @last_status: Status of the last executed command
 */
void exit_shell(char **args, int last_status)
{
	int status = last_status; /* Default to the last command's status */

	if (args[1]) /* Check for an optional exit status */
	{
		status = atoi(args[1]);
		if (status < 0) /* Invalid exit status */
		{
			write(STDERR_FILENO, "exit: Invalid status\n", 21);
			status = last_status;
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
