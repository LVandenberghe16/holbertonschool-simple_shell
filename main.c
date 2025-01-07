#include "shell.h"

/**
 * main - Entry point of the shell program
 * @argc: Argument count
 * @argv: Argument vector
 * @env: Environment variables
 *
 * Return: 0 on success, or an error code
 */
int main(int argc, char **argv, char **env)
{
	(void)argc;

	if (isatty(STDIN_FILENO))
		interactive_shell(argv, env);
	else
		non_interactive_shell(argv, env);

	return (0);
}
