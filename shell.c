#include "shell.h"

/**
 * main - shell logic
 * Return: 0 on success
 */

int main(void)
{
	void (*func)(char **);
	char *buffer = NULL, *val, *pth_nam;
	char **arr_v;
	size_t size = 0;
	ssize_t cmdlen = 0;
	path_dir *h = '\0';

	while (cmdlen != EOF)
	{
		_isterminal();
		cmdlen = getline(&buffer, &size, stdin);
		_isEOF(cmdlen, buffer);
		arr_v = splitstring(buffer, " \n");

		if (!arr_v || !arr_v[0])
		{
			exec(arr_v);
		}
		else
		{
			val = _getenv("PATH");
			h = dir_path(val);
			pth_nam = get_path(arr_v[0], h);
			func = verify_build(arr_v);
			if (func)
			{
				free(buffer);
				f(arr_v);
			}
			else if (pth_nam)
			{
				free(arr_v[0]);
				arr_v[0] = pth_nam;
				exec(arr_v);
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
