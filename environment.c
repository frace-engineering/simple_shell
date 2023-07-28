#include "shell.h"

/**
 * _getenv - gets the value of an environment variable
 * @name: name of the variable to get
 * @env: environment variable
 *
 * Description: returns the value of an environment variable
 * Return: the environment variable on success,
 * NULL on failure
 */
char *_getenv(char *name, char **env)
{
	int i, j, k, len, is_found;
	char *var;

	is_found = 0;
	len = _len(name);

	for (i = 0; env[i] != NULL; i++)
	{
		for (j = 0; name[j] != '\0'; j++)
		{
			if (name[j] == env[i][j])
				continue;
			else
				break;
		}
		if (j == len)
		{
			is_found = 1;
			break;
		}
	}
	if (is_found)
	{
		j = 0;
		while (env[i][j] != '=')
			j++;
		j++;
		for (k = 0; env[i][j + k] != '\0'; k++)
			k++;
		var = malloc(sizeof(char) * (k + 1));
		if (var == NULL)
			return (NULL);
		for (k = 0; env[i][j + k] != '\0'; k++)
			var[k] = env[i][j + k];
		var[k] = '\0';
		return (var);
	}
	return (NULL);
}
