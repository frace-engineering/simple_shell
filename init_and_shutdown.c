#include "shell.h"
#include <stdio.h>

int init_env(char **sys_env, struct core *core);

/**
 * init - initializes struct core
 * @argv: argv passed to the shell
 * @env: env passed to the shell
 * @core: the struct core to initialize
 *
 * Description: initializes struct core
 * Return: 1 is returned on success,
 * 0 is returned otherwise
 */
int init(char **argv, char **env, struct core *core)
{
	core->line = NULL;
	core->line_len = 0;
	core->argv = argv;
	core->av = NULL;
	core->command = NULL;
	core->is_pipe = isatty(STDIN_FILENO) ? 0 : 1;
	core->exit_status = 0;

	init_env(env, core);

	return (1);
}

/**
 * init_env - initializes environment variable for the shell
 * @sys_env: system environment variable
 * @core: the shell core variables
 *
 * Description: initnializes environment variable for the shell
 * Return: 1 on success, 0 on error
 */
int init_env(char **sys_env, struct core *core)
{
	int i, j, k, n;

	for (i = 0; sys_env[i] != NULL; i++)
		;

	core->env = malloc(sizeof(char *) * (i + 1));
	if (core->env == NULL)
		return (0);

	for (j = 0; j < i; j++)
	{
		for (k = 0; sys_env[j][k] != '\0'; k++)
			;
		core->env[j] = malloc(sizeof(char) * (k + 1));

		for (n = 0; n < k; n++)
			core->env[j][n] = sys_env[j][n];
		core->env[j][n] = '\0';
	}

	core->env[j] = NULL;

	return (1);
}

/**
 * shutdown - frees the core variable
 * @core: the core shell variable
 *
 * Description: frees te core variable
 *
 * return: 1 on success, 0 otherwise
 */
int shutdown(struct core *core)
{
	free(core->line);
	free_2d(core->env);
	free_2d(core->av);

	return (1);
}

/**
 * free_2d - frees a 2d array
 * @ptr: 2d array to free
 *
 * Description: frees a 2d array like env or av
 * Return: void
 */
void free_2d(char **ptr)
{
	int i;

	for (i = 0; ptr[i] != NULL; i++)
		free(ptr[i]);

	free(ptr);
} 

