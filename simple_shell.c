#include "shell.h"


/**
 * main - entry point to the function
 *
 * Return: self
 */
int main(void)
{
	size_t len;
	char *buff, *ptr;
	int is_pipe;
	pid_t pid;
	char *argv[] = {"", NULL};

	len = 1024;
	buff = malloc(sizeof(char *) * 1024);
	if (buff == NULL)
		return (0);

	is_pipe = isatty(STDIN_FILENO) ? 0 : 1;

	if(!is_pipe)
		_puts("$ ");

	getline(&buff, &len, stdin);
	ptr = strtok(buff, "\n");

	/** ptr = _strtok(buff, "\n" " "); */

	pid = fork();
	if (pid == 0)
	{
		printf("In the child proc - %s", ptr);
		execve(ptr, argv, NULL);
	}
	else
	{
		wait(&pid);
	}

	if (is_pipe)
		return (0);
	else
		return (main());
}
