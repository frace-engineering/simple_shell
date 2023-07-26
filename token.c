#include "shell.h"

/**
 * match_char - matches a chracter to characters in a string
 * @c: given character
 * @str: pointer to a string
 *
 * Return: 1 on success wlse 0
 */
int match_char(char c, const char *str)
{
	while (*str != '\0')
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}
/**
 * _strtok - tokenize a string using delimeters
 * @str: pointer to a string
 * @delim: pointer to character string of delimiters
 *
 * Description: gets next token for str
 * Return: tokens
 */
char *_strtok(char *str, const char *delim)
{
	static char *token, *next_token;
	int i;

	if (str != NULL)
		token = str;
	next_token = token;
	if (next_token == NULL)
		return (NULL);
	for (i = 0; token[i] != '\0'; i++)
	{
		if (match_char(token[i], delim) == 0)
			break;
	}
	if (token[i] == '\0' || token[i] == '#')
	{
		token = NULL;
		return (NULL);
	}
	next_token = token + i;
	token = next_token;
	for (i = 0; token[i] != '\0'; i++)
	{
		if (match_char(token[i], delim) == 1)
			break;
	}
	if (token[i] == '\0')
		next_token = NULL;
	else
	{
		token[i] = '\0';
		token = token + 1 + i;
		if (*token == '\0')
			token = NULL;
	}
	return (next_token);
}

/**
 * _tokenize - tokenise a string
 * @str: pointer to a string
 * @delim: pointer to string of delimiters
 *
 * Description: tokenizes a string
 * Return: token
 */
char **_tokenize(char *str, const char *delim)
{
	char **tokens;
	size_t num;
	size_t i;

	i = 1;
	num = 10;

	if (str == NULL)
		return (NULL);

	tokens = malloc(sizeof(char *) * num);
	if (tokens == NULL)
	{
		perror("malloc");
		return (NULL);
	}

	tokens[0] = strtok(str, delim);

	while ((tokens[i] = strtok(NULL, delim)) != NULL)
	{
		i++;
		if (i == num)
		{
			tokens = _realloc2(tokens, &num);
			if (tokens == NULL)
			{
				perror("realloc");
				return (NULL);
			}
		}
	}

	return (tokens);
}
