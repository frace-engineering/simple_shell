#include "shell.h"
#include <stdio.h>

int run_path(char *full_path, struct core *core);

/**
 * find_exec - finds appropriate execution command for @name
 * @name: name of the command to execute
 *
 * Description: looks at name and determines appropriate
 * function to execute functions of that type
 * depending on whether name is a fully qualified path
 * path in in the current working directory
 * or path in the PATH environment variable
 * Return: pointer to appropriate function to execute
 * command @name
 */
int (*find_exec(char *name))(struct core *core)
{
	int i;

	exec_funcs funcs[] = {
		{'/', exec_full_path},
		{'.', exec_cwd},
		{'\0', NULL}
	};

	if (name[0] >= 'a' && name[0] <= 'z')
		return (exec_path);

	return (exec_full_path);

	for (i = 0; funcs[i].c != '\0'; i++)
	{
		if (name[0] == funcs[i].c)
			return (funcs[i].f);
	}

	return (NULL);
}

/**
 * exec_full_path - executes command with full path
 * @core: pointer to core var of the shell
 *
 * Description: executes command when full path is supplied
 * Return: On success 1, on error 0
 */
int exec_full_path(struct core *core)
{
	pid_t pid;
	int wstatus;

	pid = fork();

	if (pid == 0)
	{
		if (execve(core->av[0], core->av, core->env) == -1)
		{
			if (core->is_pipe)
				exit(127);
			else
				perror("execve");
		}
	}
	else
	{
		wait(&wstatus);
	}

	return (1);
}

/**
 * exec_path - executes command when command is in PATH env var
 * @core: the shell core variables
 *
 * Description: executes commands ind PATH env var
 * Return: on success 1, on error 0
 */
int exec_path(struct core *core)
{
	char *path; /* remember to free */
	char full_path[50] = {0};
	char *tok;
	char *delim = ":";
	struct stat stat_buf;

	path = _getenv("PATH", core->env);

	tok = strtok(path, delim);

	for (; tok != NULL;)
	{
		_strcat(full_path, tok);
		_strcat(full_path, "/");
		_strcat(full_path, core->av[0]);

		if (stat(full_path, &stat_buf) == 0)
		{
			run_path(full_path, core);

			return (1);
		}


		tok = strtok(NULL, delim);
		_reset(full_path);
	}

	perror("Command not found\n");

	return (1);
}

/**
 * exec_cwd - executes command in the current working dir
 * @core: the shell's core variables
 *
 * Description: executes commands that are in the current working dir
 * Return: On success 1, on failure 0
 */
int exec_cwd(struct core *core)
{
	(void) core;
	printf("exec cwd");

	return (1);
}

/**
 * run_path - runs command in one of the dirs in PATH var
 * @full_path: full path of the command
 * @core: the shell core vars
 *
 * Description: runs command in one of the dirs in PATH var
 * Return: on sucess 1 is returned, 0 on error
 */
int run_path(char *full_path, struct core *core)
{
	pid_t pid;

	if (access(full_path, X_OK) == 0)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(1);
		}
		if (pid == 0)
		{
			if (execve(full_path, core->av, core->env) == -1)
			{
				perror("execve");
				printf("from here");
				exit(1);
			}
		}
		else
		{
			wait(&core->wstatus);
			return (1);
		}
	}
	else
	{
		perror(":Permission denied");
		core->exit_status = 126;
	}

	return (0);
}

