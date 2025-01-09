#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>

void interactive_shell(char **argv, char **env);
void non_interactive_shell(char **argv, char **env);
void execute_command(char **args, char **argv, char **env);
void exit_shell(char **args);
void print_env(char **env);
char *resolve_path(char *cmd, char **env);
char **parse_line(char *line);
int _strcmp(char *s1, char *s2);

#endif /* SHELL_H */
