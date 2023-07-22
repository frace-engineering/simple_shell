#include "shell.h"

/**
 * _len - get the length of a string
 * @str: pointer to the string
 *
 * Return: length of the string
 */
int _len(char *str)
{
	if (*str != '\0')
		return (1 + _len(str + 1));
	return (0);
}
/**
 * _putchar - prints character to the stdout
 * @c: input character
 *
 * Return: number of character
 */
int _putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
/**
 * _puts - prints string to the stdout
 * @str: pointer to a string
 *
 * Return: void
 */
int _puts(char *str)
{
	ssize_t count, len;

	count = _len(str);
	len = write(STDOUT_FILENO, str, count + 1);
	return (len);
}
/**
 * _uitoa - converts number to a string
 * @count: given number
 *
 * Return: pointer to string
 */
char *_uitoa(unsigned int count)
{
	unsigned int i, temp, digits;
	char *numstr;

	temp = count;
	for (digits = 0; temp != 0; digits++)
		temp = temp / 10;
	numstr = malloc(sizeof(char) * (digits + 1));
	if (numstr == NULL)
	{
		perror("Fatal error!");
		exit(1);
	}
	numstr[digits] = '\0';
	for (i = digits - 1; count; i--)
	{
		numstr[i] = (count % 10) + '0';
		count /= 10;
	}
	return (numstr);
}
