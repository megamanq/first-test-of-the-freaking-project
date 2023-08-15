#include "shell.h"

/**
 * _strlen - calculate the length of a string
 * @s: pointer to string
 * Return: string length
 */
int _strlen(char *s)
{
	int i = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		continue;
	}
	return (i);
}

/**
 * _strdup - duplicate a string in a new array
 * @str: pointer to string
 * Return: pointer to duplicated string
 */
char *_strdup(char *str)
{
	int i, len;
	char *dup;

	if (!str)
	{
		return (NULL);
	}

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}

	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
	{
		return (NULL);
	}

	i = 0;
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}

	dup[len] = str[len];

	return (dup);
}

/**
 * splitstr - split a string and save it as an array of words
 * @str: string pointer to be split
 * @delime: delimiter
 * Return: pointer to an array of strings (pointers)
 */
char **splitstr(char *str, const char *delime)
{
	int i, c;
	char **arr;
	char *tkn;
	char *str_copy;

	str_copy = malloc(sizeof(char) * (_strlen(str) + 1));
	if (str_copy == NULL)
	{
		perror(_getenv("_"));
		return (NULL);
	}

	i = 0;
	while (str[i])
	{
		str_copy[i] = str[i];
		i++;
	}
	str_copy[i] = '\0';

	tkn = strtok(str_copy, delime);
	arr = malloc((sizeof(char *) * 2));
	if (arr == NULL)
	{
		perror(_getenv("_"));
		return (NULL);
	}
	arr[0] = _strdup(tkn);
	i = 1;
	c = 3;
	while (tkn)
	{
		tkn = strtok(NULL, delime);
		arr = _realloc(arr, (sizeof(char *) * (c - 1)), (sizeof(char *) * c));
		arr[i] = _strdup(tkn);
		i++;
		word_counter++;
	}
	free(str_copy);
	return (arr);
}
