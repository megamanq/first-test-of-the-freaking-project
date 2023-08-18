#include "shell.h"

/**
 * _strdup - duplicate a string in new array
 * @str: ptr to str
 * Return: pter to uplicated str
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
 * concat_all - concat strings in another memory
 * @n: first str name
 * @s: second str seperator
 * @v: Third str value
 * Return: ptr to new str
 */

char *concat_all(char *n, char *s, char *v)
{
	char *res;
	int lenn, lens, lenv, i, j;

	lenn = _strlen(n);
	lens = _strlen(s);
	lenv = _strlen(v);
	res = malloc(lenn + lens + lenv + 1);
	if (!res)
	{
		return (NULL);
	}
	i = 0;
	while (n[i])
	{
		res[i] = n[i];
		i++;
	}
	j = i;
	i = 0;
	while (s[i])
	{
		res[j + i] = s[i];
		i++;
	}
	j += i;
	i = 0;
	while (v[i])
	{
		res[j + i] = v[i];
		i++;
	}
	j += i;
	res[j] = '\0';
	return (res);
}

/**
 * _atoi - turn str to int
 *@str: ptr to str
 *Return: int
 */

int _atoi(char *str)
{
	int j, intgr, sig = 1;

	j = 0;
	while (!((str[j] >= '0') && (str[j] <= '9')) && (str[j] != '\0'))
	{
		if (str[j] == '-')
		{
			sig = sig * (-1);
		}
		j++;
	}
	intgr = 0;
	while ((str[j] >= '0') && (str[j] <= '9'))
	{
		intgr = (intgr * 10) + (sig * (str[j] - '0'));
		j++;
	}
	return (intgr);
}

/**
 * _putchar - print char to stdout
 * @c: char to print
 * Return: 1 on success,-1 i fail
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
