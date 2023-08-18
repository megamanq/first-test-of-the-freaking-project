
/**
 * _strlen - calculate the lenght of a str
 * @s: ptr to str
 * Return: str lenght
 */

int _strlen(char *s)
{
	int i = 0;

    for (i = 0; s[i] != '\0'; i++)
    {
        continue;
    }
	return (i);
}

/**
 * _puts - print as str
 * @s: ptr to str
 */

void _puts(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		_putchar(s[i]);
	}
}


/**
 * splitstr - split a string and save it as array of words
 * @str: str ptr to be splited
 * @delime: delimiter
 * Return: pointer to array of strings (pointers)
 */

char **splitstr(char *str, const char *delime)
{
	int i, word_counter;
	char **arr;
	char *tkn;
	char *str_copy;

	str_copy = malloc(sizeof(char) * (_strlen(str) + 1));
	if (str_copy == NULL)
	{
		perror(_getenv("_"));
		return (NULL);
	}
    i = 0;
	while (str[i])
	{
		str_copy[i] = str[i];
        i++;
	}
	str_copy[i] = '\0';

	tkn = strtok(str_copy, delime);
	arr = malloc((sizeof(char *) * 2));
	if (arr == NULL)
	{
		perror(_getenv("_"));
		return (NULL);
	}
	arr[0] = _strdup(tkn);
    i = 1;
    word_counter = 3;
	while (tkn)
	{
		tkn = strtok(NULL, delime);
		arr = _realloc(arr, (sizeof(char *) * (word_counter - 1)), (sizeof(char *) * word_counter));
		arr[i] = _strdup(tkn);
        i++;
        word_counter++;
	}
	free(str_copy);
	return (arr);
}
