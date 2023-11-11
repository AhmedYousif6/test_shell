#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

char **tokenizer(char *str, char *deli);
char *read_line(void);
void exec(char **args);
void handle_sigint(int sig);

#endif
