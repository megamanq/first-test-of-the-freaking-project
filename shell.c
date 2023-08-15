#include "shell.h"

/**
 * main - shell logic
 * Return: 0 on success
 */

int main(void)
{
	ssize_t cmdlen = 0;
	char *buffer = NULL;
	char **arv;
	size_t size = 0;

	while (cmdlen != EOF)
	{
		_isterminal();
		cmdlen = getline(&buffer, &size, stdin);
		_isEOF(cmdlen, buffer);
		arv = splitstring(buffer, " \n");

		if (!arv || !arv[0])
		{
			execute(arv);
		}
	}
}
