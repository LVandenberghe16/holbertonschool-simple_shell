#include "shell.h"

/**
 * resolve_path - Resolves the full path of a command
 * @cmd: Command to resolve
 * @env: Environment variables
 *
 * Return: Full path of the command, or NULL if not found
 */
char *resolve_path(char *cmd, char **env)
{
	char *path = NULL, *dir = NULL, *full_path = NULL;
	struct stat st;
	size_t i;

	if (stat(cmd, &st) == 0 && (st.st_mode & S_IXUSR))
		return (strdup(cmd)); /* Command is an absolute path */

	/* Search for PATH in the env array */
	for (i = 0; env[i]; i++)
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
		{
			path = env[i] + 5; /* Skip "PATH=" */
			break;
		}
	}

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
