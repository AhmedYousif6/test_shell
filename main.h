#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>

extern char **environ;
char **tokenizer(char *str, char *deli);
char *read_line(void);
char *get_path(char *cmmd);
void exec(char **args);
void handle_sigint(int sig);
void free_array(char **args);
void prompt(void);
char *cmd_path(char *command);
void print_env(void);

#endif
