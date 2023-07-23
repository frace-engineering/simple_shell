#include "shell.h"


/**
 * main - entry point to the function
 *
 * Return: self
 */
int main(int argc __attribute__((unused)), char **argv, char **env)
{
	size_t len;
	char *buff, *ptr;
	int is_pipe;
	pid_t pid;
	int wstatus;
	/** char *argv[] = {"", NULL}; */

	len = 1024;
	buff = malloc(sizeof(char *) * 1024);
	if (buff == NULL)
		return (0);

	is_pipe = isatty(STDIN_FILENO) ? 0 : 1;

	if(!is_pipe)
		_puts("$ ");

	while (getline(&buff, &len, stdin) != -1)
	{
		ptr = strtok(buff, "\n ");

		pid = fork();
		if(pid == 0)
		{
			if (execve(ptr, argv, env) == -1)
			{
				if (is_pipe)
					exit (127);
				else
				{
					perror("execve");
				}
			}
		}
		else
		{
			wait(&wstatus);
		}
		if (is_pipe == 0)
			_puts("$ ");
	}
			

	/** ptr = _strtok(buff, "\n" " "); */


	if (is_pipe)
		return (0);

	return (0);
}
