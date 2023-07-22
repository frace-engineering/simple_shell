#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
int _len(char *str);
int _putchar(char c);
int _puts(char *str);
char *_uitoa(unsigned int count);
int match_char(char c, const char *str);
char *_strtok(char *str, const char *delim);
char *tokenize(char *str, const char *delim);


#endif /* _SHEL_H_ */
