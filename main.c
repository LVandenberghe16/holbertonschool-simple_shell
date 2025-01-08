#include "shell.h"
#include <signal.h>

void handle_sigint(int sig);

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

	signal(SIGINT, handle_sigint);

	if (isatty(STDIN_FILENO))
		interactive_shell(argv, env);
	else
		non_interactive_shell(argv, env);

	return (0);
}

/**
 * handle_sigint - Signal handler for SIGINT (Ctrl+C)
 * @sig: Signal number (unused)
 */
void handle_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n($) ", 5);
}
