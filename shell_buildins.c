#include "shell.h"

/**
 * cust_exit - exit the shell
 * @arw: arr of wrds of comnd
 */

void cust_exit(char **arw)
{
	int i, ata;

	if (arw[1])
	{
		ata = _atoi(arw[1]);
		if (ata <= -1)
			ata = 2;
		free_arr(arw);
		exit(ata);
	}
	i = 0;
	while (arw[i])
	{
		free(arw[i]);
		i++;
	}
	free(arw);
	exit(0);
}

/**
 * print_env - print current env
 * @arr_args: arr of args
 */

void print_env(char **arr_args __attribute__ ((unused)))
{
	int i;

    i = 0;
	while (environ[i])
	{
		_puts(environ[i]);
		_puts("\n");
        i++;
	}
}

/**
 * set_env - start new env var or chnge existing
 * @arr_wrds: arr of entred wrd
 */

void set_env(char **arr_wrds)
{
	int l, m, n;

	if (!arr_wrds[1] || !arr_wrds[2])
	{
		perror(_getenv("_"));
		return;
	}
	for (l = 0; environ[l]; l++)
	{
		m = 0;
		if (arr_wrds[1][m] == environ[l][m])
		{
			while (arr_wrds[1][m])
			{
				if (arr_wrds[1][m] != environ[l][m])
					break;
				m++;
			}
			if (arr_wrds[1][m] == '\0')
			{
				n = 0;
				while (arr_wrds[2][n])
				{
					environ[l][m + 1 + n] = arr_wrds[2][n];
					n++;
				}
				environ[l][m + 1 + n] = '\0';
				return;
			}
		}
	}
	if (!environ[l])
	{
		environ[l] = concat_all(arr_wrds[1], "=", arr_wrds[2]);
		environ[l + 1] = '\0';
	}
}

/**
 * unset_env - delete env var
 * @arr_wrd: arr of entred wrds
 */

void unset_env(char **arr_wrd)
{
	int l, m;

	if (!arr_wrd[1])
	{
		perror(_getenv("_"));
		return;
	}
	l = 0;
	while (environ[l])
	{
		m = 0;
		if (arr_wrd[1][m] == environ[l][m])
		{
			for (; arr_wrd[1][m]; m++)
			{
				if (arr_wrd[1][m] != environ[l][m])
					break;
			}
			if (arr_wrd[1][m] == '\0')
			{
				free(environ[l]);
				environ[l] = environ[l + 1];
				for (; environ[l]; l++)
				{
					environ[l] = environ[l + 1];
				}
				return;
			}
		}
		l++;
	}
}
