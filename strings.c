#include "shell.h"

/**
 * _len - get the length of a string
 * @str: pointer to the string
 *
 * Return: length of the string
 */
int _len(char *str)
{
	if (str == NULL)
		return (0);

	if (*str != '\0')
		return (1 + _len(str + 1));
	return (0);
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

/**
 * _strcat - concatenates 2 strings
 * @s1: destination string
 * @s2: source string
 *
 * Description: concatenates strings 1 and 2 together
 * Return: pointer to the concatenated string
 */
char *_strcat(char *s1, char *s2)
{
	int i, j;

	if (s2 == NULL)
		return (s1);

	for (i = 0; s1[i] != '\0'; i++)
		;

	for (j = 0; s2[j] != '\0'; j++)
		s1[i + j] = s2[j];

	s1[i + j] = '\0';

	return (s1);
}

/**
 * _strdup - duplicates a string
 * @s: the string to duplicate
 *
 * Description: duplicates a string
 * Return: pointer to the string
 */
char *_strdup(char *s)
{
	int i;
	char *p;

	if (s == NULL)
		return (NULL);

	for (i = 0; s[i] != '\0'; i++)
		;

	p = malloc(sizeof(char) * (i + 1));

	for (i = 0; s[i] != '\0'; i++)
	{
		p[i] = s[i];
	}

	p[i] = '\0';

	return (p);
}
