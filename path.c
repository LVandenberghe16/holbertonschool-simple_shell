#include "shell.h"

/**
 * resolve_path - Resolves the full path of a command
 * @cmd: Command to resolve
 *
 * Return: Full path of the command, or NULL if not found
 */
char *resolve_path(char *cmd)
{
	char *path, *dir, *full_path;
	struct stat st;

	if (stat(cmd, &st) == 0 && (st.st_mode & S_IXUSR))
		return (strdup(cmd)); /* Command is an absolute path */

	path = getenv("PATH");
	if (!path)
		return (NULL);

	path = strdup(path); /* Duplicate PATH */
	dir = strtok(path, ":");

	while (dir)
	{
		full_path = malloc(strlen(dir) + strlen(cmd) + 2);
		if (!full_path)
		{
			free(path);
			return (NULL);
		}

		sprintf(full_path, "%s/%s", dir, cmd);

		if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
		{
			free(path);
			return (full_path);
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}

	free(path);
	return (NULL);
}
