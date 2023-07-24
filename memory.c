#include "shell.h"

#define NUM 10

int min(int a, int b)
{
	return (a > b ? a : b);
}

/**
 * _realloc1 - reallocates char *
 * @ptr: pointer to string
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
