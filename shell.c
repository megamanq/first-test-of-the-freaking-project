#include "shell.h"

/**
 * ispath - execute when pathnam true
 * @arr: array of pointer of pointers
 * @path: pointer of chars
*/

void ispath_nam(char **arr, char *path)
{
	free(arr[0]);
	arr[0] = path;
	exec(arr);
}

/**
 * isfunc - execute when func true
 * @arr: array of pointer of pointers
 * @buf: pointer of chars
*/

void isfunc(char *buf, char **arr, void (*func)(char **))
{
	free(buf);
	func(arr);
}

/**
 * man_dir - manipulating directory paths
 * @v: value
 * @head: pointer to h
 * @path: pth nam
 * @arr: arr_v
 */

void man_dir(char *v, path_dir *head, char *path, char **arr)
{
	v = _getenv("PATH");
	head = dir_path(v);
	path = get_path(arr[0], head);
}

/**
 * main - shell logic
 * Return: 0 on success
 */

int main(void)
{
	void (*func)(char **);
	char **arr_v, *buffer = NULL, *val, *pth_nam;
	size_t size = 0;
	ssize_t cmdlen = 0;
	path_dir *h = '\0';

	signal(SIGINT, ctrl_c);
	while (cmdlen != EOF)
	{
		_isterminal();
		cmdlen = getline(&buffer, &size, stdin);
		_isEOF(cmdlen, buffer);
		arr_v = splitstr(buffer, " \n");
		if (!arr_v || !arr_v[0])
		{
			exec(arr_v);
		}
		else
		{
			man_dir(val, h, pth_nam, arr_v);
			func = verify_build(arr_v);
			if (func)
			{
				isfunc(buffer, arr_v, func());
			}
			else if (pth_nam)
			{
				ispath_nam(arr_v, pth_nam);
			}
			else if (!pth_nam)
			{
				exec(arr_v);
			}
		}
	}
	free_lst(h);
	free_arr(arr_v);
	free(buffer);
	return (0);
}
