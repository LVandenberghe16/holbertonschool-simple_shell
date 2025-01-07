#include "shell.h"

/**
 * resolve_path - Resolves the full path of a command
 * @cmd: Command to resolve
 *
 * Return: Full path of the command, or NULL if not found
 */
char *resolve_path(char *cmd)
{
	char *path = getenv("PATH");
	char *dir, *full_path;
	struct stat st;

	if (stat(cmd, &st) == 0)
		return (cmd);

	dir = strtok(path, ":");
	while (dir)
	{
		full_path = malloc(strlen(dir) + strlen(cmd) + 2);
		if (!full_path)
			return (NULL);

		sprintf(full_path, "%s/%s", dir, cmd);
		if (stat(full_path, &st) == 0)
			return (full_path);

		free(full_path);
		dir = strtok(NULL, ":");
	}
	return (NULL);
}
