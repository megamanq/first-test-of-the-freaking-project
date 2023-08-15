#include "shell.h"

/**
 * _realloc - Reallocate block memiorry
 * @ptr: old ptr
 * @old_s: old size
 * @new_s: new size
 * Return: New ptr
 */

void *_realloc(void *ptr, unsigned int old_s, unsigned int new_s)
{
	char *new_mem, *old_mem = ptr;
	unsigned int i;

	if (ptr == NULL)
		return (malloc(new_s));
	if (new_s == old_s)
		return (ptr);
	if (new_s == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	new_mem = malloc(new_s);
	if (new_mem == NULL)
		return (NULL);
	if (new_s > old_s)
	{
		i = 0;
		while (i < old_s)
		{
			new_mem[i] = old_mem[i];
			i++;
		}
		free(ptr);
		for (i = old_s; i < new_s; i++)
		{
		new_mem[i] = '\0';
		}
	}
	if (new_s < old_s)
	{
		i = 0;
		while (i < new_s)
		{
			new_mem[i] = old_mem[i];
			i++;
		}
		free(ptr);
	}
	return (new_mem);
}
