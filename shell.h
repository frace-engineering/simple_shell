#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

/**
 * struct core - core data structure of the shell
 * @line: input line when the shell is invoked
 * @line_len: length of line
 * @argv: argv supplied to the shell
 * @av: argument vectore supplied to running program
 * @command: current command being run by the shell
 * @env: copy of environment variable supplied to the main
 * @is_pipe: false for interactive mode, true for non-interactive mode
 * @wstatus: wait status for the current command
 * @exit_status: exit status of the shell
 *
 * Description: the core data structure of the shell
 */
struct core
{
	char *line;
	size_t line_len;
	char **argv;
	char **av;
	char **command;
	char **env;
	int is_pipe;
	int wstatus;
	int exit_status;
};

/**
 * struct exec_funcs - struct for the execution functions
 * @c: first char to check
 * @f: function to return
 *
 * Description: struct for the execution functions
 */
typedef struct exec_funcs
{
	char c;
	int (*f)(struct core *core);
} exec_funcs;

/* write functions */
int _putchar(char c);
int _puts(char *c);
void print_error(struct core *core, char *msg);

/* string functions */
int _len(char *str);
char *_uitoa(unsigned int count);
int match_char(char c, const char *str);
char *_strtok(char *str, const char *delim);
char *_strcat(char *s1, char *s2);
char *_strdup(char *s);
char **_tokenize(char *str, const char *delim);

/* memory */
char *_realloc1(char *ptr, int size);
char **_realloc2(char **ptr, size_t *size);
void _reset(char buf[]);

/* initialization and shutdown */
int init(char **argv, char **env, struct core *core);
int shutdown(struct core *core);
void free_2d(char **ptr);

/* environment */
char *_getenv(char *name, char **env);

/* execution commands */
int exec_full_path(struct core *core);
int exec_path(struct core *core);
int exec_cwd(struct core *core);
int (*find_exec(char *name))(struct core *core);

#endif /* _SHEL_H_ */
