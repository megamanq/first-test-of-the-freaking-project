#include "shell.h"

/**
 * dir_path - make linkedlist for PATH directories
 * @path: PATH value (STRING)
 * Return: ptr to linkedlist
 */

path_dir *dir_path(char *path)
{
	path_dir *h = '\0';
	char *tkn;
	char *path_copy = _strdup(path);

	tkn = strtok(path_copy, ":");
	while (tkn)
	{
		h = add_at_end(&h, tkn);
		tkn = strtok(NULL, ":");
	}
	free(path_copy);
	return (h);
}

/**
 * add_at_end - add node at the end of a list
 * @h: ptr to ptr linked list
 * @str: ptr to str in prev node
 * Return: addr of new node
 */

path_dir *add_at_end(path_dir **h, char *str)
{

	path_dir *temp;
	path_dir *new_node;

	new_node = malloc(sizeof(path_dir));
	if (!new_node || !str)
		return (NULL);
	new_node->dir = str;
	new_node->p = '\0';
	if (!*h)
	{
		*h = new_node;
	}
	else
	{
		temp = *h;
		while (temp->p)
		{
			temp = temp->p;
		}
		temp->p = new_node;
	}
	free(new_node);
	return (*h);
}
