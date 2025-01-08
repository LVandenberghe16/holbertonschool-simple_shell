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

	/* Check if the command is already an absolute path */
	if (stat(cmd, &st) == 0 && (st.st_mode & S_IXUSR))
		return (strdup(cmd)); /* Return a copy of the command */

	/* Get the PATH environment variable */
	path = getenv("PATH");
	if (!path)
		return (NULL); /* PATH not set */

	/* Tokenize the PATH and search for the command */
	path = strdup(path); /* Duplicate to avoid modifying original */
	dir = strtok(path, ":");
	while (dir)
	{
		/* Construct the full path */
		full_path = malloc(strlen(dir) + strlen(cmd) + 2);
		if (!full_path)
		{
			free(path);
			return (NULL); /* Memory allocation failure */
		}
		sprintf(full_path, "%s/%s", dir, cmd);

		/* Check if the file exists and is executable */
		if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
		{
			free(path); /* Free the duplicated PATH */
			return (full_path); /* Return the resolved path */
		}

		free(full_path); /* Free the constructed path */
		dir = strtok(NULL, ":");
	}

	free(path); /* Free the duplicated PATH */
	return (NULL); /* Command not found */
}
