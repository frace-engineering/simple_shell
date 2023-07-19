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
	pid_t pid;
	char *argv[] = {"", NULL};


	len = 1024;
	buff = malloc(sizeof(char *) * 1024);
	if (buff == NULL)
		return (0);
	printf("$ ");
	getline(&buff, &len, stdin);

	ptr = strtok(buff, "\n");
	pid = fork();
	if (pid == 0)
	{
		execve(ptr, argv, NULL);
	}
	else
	{
		wait(&pid);
	}
	return (main());
}
