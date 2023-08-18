#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

/**
 * struct cm_func - pointer to function with corresponding buildin command
 * @name: buildin command
 * @func: execute the buildin command
 */

typedef struct cm_func
{
	char *n;
	void (*f)(char **);
} cm_func;

/**
 * struct path_dir - list of PATH directories
 * @dir: directory
 * @p: ptr for next node
 */

typedef struct path_dir
{
	char *dir;
	struct path_dir *p;
} path_dir;

/**
 * terminal_handlers
 */

void _isterminal(void);
void _isEOF(int cmdlen, char *buffer);
void exec(char **arr_args);
void ctrl_c(int ctrl_signal);

/**
 * shell_buildins
 */

void cust_exit(char **arw);
void print_env(char **arr_args __attribute__ ((unused)));
void set_env(char **arr_wrds);
void unset_env(char **arr_wrd);

/**
 * string_func
 */

char *_strdup(char *str);
int _atoi(char *str);
int _putchar(char c);
char *concat_all(char *n, char *s, char *v);

/**
 * more_string_func
 */

int _strlen(char *s);
void _puts(char *s);
char **splitstr(char *str, const char *delime);

/**
 * path_func
 */

char *_getenv(const char *gv);
char *get_path(char *fname, path_dir *h);
void(*verify_build(char **arg))(char **arg);

/**
 * list_func
 */

path_dir *dir_path(char *path);
path_dir *add_at_end(path_dir **h, char *str);

/**
 * memory_alloc
 */

void *_realloc(void *ptr, unsigned int old_s, unsigned int new_s);
void free_lst(path_dir *h);
void free_arr(char **arr);

/**
 * shell
 */

void ispath_nam(char **arr, char *path);
void isfunc(char *buf, char **arr);
void man_dir(char *v, path_dir *head, char *path, char **arr);

#endif
