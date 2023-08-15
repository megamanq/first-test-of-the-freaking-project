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
