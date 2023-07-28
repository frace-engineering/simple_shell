#include "shell.h"

/**
 * _putchar - writes a char to stdout
 * @c: the character to write
 *
 * Description: writes a char to stdout
 * Return: 1
 */
int _putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

/**
 * _puts - writes a string to stdout
 * @str: the string to write
 *
 * Description: writes a string to stdout
 * Return: the number of string written
 */
int _puts(char *str)
{
	ssize_t count, len;

	count = _len(str);
	len = write(STDOUT_FILENO, str, count + 1);
	return (len);
}

/**
 * print_error - prints error
 * @core: the core variable of the shell
 * @msg: optional message to print
 *
 * Description: prints error message to stdout
 * Return: void
 */
void print_error(struct core *core, char *msg)
{
	_puts(core->av[0]);
	_puts(": ");

	if (msg != NULL)
	{
		_puts(msg);
		_puts("\n");
	}
	else
		perror("");
}
