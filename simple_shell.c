#include "shell.h"

/**
 * main - entry point to the function
 * @argc: argument count
 * @argv: argument vector
 * @env: environment variable
 *
 * Description: main function
 * Return: self
 */
int main(int argc __attribute__((unused)), char **argv, char **env)
{
	struct core core;
	int (*f)(struct core *core);

	init(argv, env, &core);

	/*signal(SIGINT, signalHandler); */

	if (!core.is_pipe)
		_puts("$ ");

	while (getline(&core.line, &core.line_len, stdin) != -1)
	{
		if (core.line[0] == '\n' && !core.is_pipe)
		{
			_puts("$ ");
			continue;
		}
		else if (core.line[0] == '\n' && core.is_pipe)
		{
			break;
		}

		core.av = _tokenize(core.line, " \n\t\r");
		f = find_exec(core.av[0]);

		if (f != NULL)
			f(&core);
		else
		{
			print_error(&core, "An error occured");
		}

		if (core.is_pipe == 0)
			_puts("$ ");
	}

	/*shutdown(&core);*/

	return (0);
}
