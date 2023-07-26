#include "shell.h"

#define NUM 10

/**
 * min - returns min of two ints
 * @a: first int
 * @b: second int
 *
 * Description: returns mins of @a and @b
 * Return: either @a or @b
 */
int min(int a, int b)
{
	return (a > b ? a : b);
}

/**
 * _realloc1 - reallocates char *
 * @ptr: pointer to string
 * @size: size of @ptr
 *
 * Description: reallocates a string buffer
 * Return: new memory reallocated
 */
char *_realloc1(char *ptr, int size)
{
	char *new;
	int i;
	int new_size;

	if (ptr == NULL)
	{
		new = malloc(sizeof(char) * size);
		if (new == NULL)
			return (NULL);
		return (new);
	}

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}

	new = malloc(sizeof(char) * size);
	if (new == NULL)
	{
		return (NULL);
	}

	new_size = min(size, _len(ptr));

	for (i = 0; i < new_size && ptr[i] != '\0'; i++)
	{
		new[i] = ptr[i];
	}

	if (ptr[i] == '\0' && i <= new_size)
		new[i] = '\0';

	return (new);
}

/**
 * _realloc2 - reallocates memory for a char ** block
 * @ptr: pointer to memory
 * @size: new size
 *
 * Description: reallocates memory for char **
 * Return: the reallocated memory
 */
char **_realloc2(char **ptr, size_t *size)
{
	char **new;
	size_t i;

	new = malloc(sizeof(char *) * ((*size) + NUM));
	if (new == NULL)
	{
		free(ptr);
		return (NULL);
	}
	for (i = 0; i < (*size); i++)
		new[i] = ptr[i];

	*size += 10;
	free(ptr);
	return (new);
}

/**
 * _reset - resets all bytes of a buffer to 0
 * @buf: pointer to memory
 *
 * Description: resets all bytes of a buffer to null byte
 * Return: void
 */
void _reset(char buf[])
{
	int i;

	i = 0;

	while (buf[i] != '\0')
	{
		buf[i] = '\0';
		i++;
	}
}
