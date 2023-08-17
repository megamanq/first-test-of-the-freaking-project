#include "shell.h"

/**
 * _getenv - extrude value of global variable
 * @gv: global variable
 * Return: ptr to value
 */

char *_getenv(const char *gv)
{
	int indi = 0, indj;
	char *variable_value;
	if (!gv)
    {
		return (NULL);
    }
    for (; environ[indi]; indi++)
	{
		indj = 0;
		if (environ[indi][indj] == gv[indj])
		{
			while (gv[indj])
			{
				if (gv[indj] != environ[indi][indj])
				{
                    break;
                }
				indj++;
			}
			if (gv[indj] == '\0')
			{
				variable_value = (1 + indj + environ[indi]);
				return (variable_value);
			}
		}
	}
	return (0);
}

/**
 * get_path - get pathname of commande
 * @fname: name of command
 * @h: head of linkdlist
 * Return: path of fname in success || NULL
 */

char *get_path(char *fname, path_dir *h)
{
	struct stat st_path;
	char *str;
	path_dir *temp = h;

	while (temp)
	{
		str = concat_all(temp->dir, "/", fname);
		if (stat(str, &st_path) == 0)
			return (str);
		free(str);
		temp = temp->p;
	}
	return (NULL);
}

/**
* verify_build - verify if command is buildin
* @arg: arr of args
* Return: ptr to func
*/

void(*verify_build(char **arg))(char **arg)
{
	int l, m;
	cm_func list[] = {
		{"exit", cust_exit},
		{"env", print_env},
		{"setenv", set_env},
		{"unsetenv", unset_env},
		{NULL, NULL}
	};

	l = 0;
	while (list[l].n)
	{
		m = 0;
		if (list[l].n[m] == arg[0][m])
		{
			for (m = 0; arg[0][m]; m++)
			{
				if (list[l].n[m] != arg[0][m])
					break;
			}
			if (!arg[0][m])
				return (list[l].f);
		}
		l++;
	}
	return (0);
}
