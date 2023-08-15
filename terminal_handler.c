#include "shell.h"

/**
 * _isterminal - check if it's a terminal
 */

void _isterminal(void)
{
	int t;

	t = isatty(STDIN_FILENO);
	if (t)
		_puts("#cisfun$ ");
}

/**
 * _isEOF - Handle End of File condition
 * @cmdlen: value of getline
 * @buffer: pointer to char type buffer
 */

void _isEOF(int cmdlen, char *buffer)
{
	(void) buffer;
	int t = isatty(STDIN_FILENO);

	if (cmdlen == -1)
	{
		if (t)
		{
			_puts("\n");
			free(buffer);
		}
		exit(0);
	}
}

