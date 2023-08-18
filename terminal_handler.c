#include "shell.h"

/**
  * _isterminal- check if it's terminal
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
* @cmdlen:  value of getline
* @buffer: pointer to char type buffer
 */

void _isEOF(int cmdlen, char *buffer)
{
	int t;
	(void)buffer;
	
	t = isatty(STDIN_FILENO);
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

/**
 * exec - execute a comnd
 * @arr_args: arr of args
 */

void exec(char **arr_args)
{

	int p, st;

	if (!arr_args || !arr_args[0])
		return;
	p = fork();
	if (p == -1)
	{
		perror(_getenv("_"));
	}
	if (p == 0)
	{
		execve(arr_args[0], arr_args, environ);
			perror(arr_args[0]);
		exit(EXIT_FAILURE);
	}
	wait(&st);
}

/**
 * ctrl_c - verify if Contorol C press
 * @ctrl_signal: int
 */

void ctrl_c(int ctrl_signal)
{
	if (ctrl_signal == SIGINT)
	{
		_puts("\n#cisfun$ ");
	}
}
