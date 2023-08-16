#include "shell.h"

/**
 * _realloc - Reallocate block memory
 * @ptr: old ptr
 * @old_s: old size
 * @new_s: new size
 * Return: New ptr
 */

void *_realloc(void *ptr, unsigned int old_s, unsigned int new_s)
{
	char *new_mem, *old_mem;
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
	old_mem = ptr;
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
			new_mem[i] = '\0';
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

/**
 * free_arr - free arr
 * @arr: arr of ptr
 */

void free_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

/**
 * free_lst - free a list
 * @h: ptr to list
 */

void free_lst(path_dir *h)
{
	path_dir *old_mem;

	while (h)
	{
		old_mem = h->p;
		free(h->dir);
		free(h);
		h = old_mem;
	}
}
