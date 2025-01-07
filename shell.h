#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

void interactive_shell(char **argv, char **env);
void non_interactive_shell(char **argv, char **env);
void execute_command(char **args, char **argv, char **env);
char *resolve_path(char *cmd);
char **parse_line(char *line);
int _strcmp(char *s1, char *s2);

#endif /* SHELL_H */
