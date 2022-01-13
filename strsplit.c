#include "monty.h"

/**
* _strncpy - copy string until n char
* @dest: string destination
* @src: string source
* @n: integer (limit)
* Return: value of dest
*/

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i]; i++)
		dest[i] = src[i];
	for (; i < n; i++)
		dest[i] = '\0';
	dest[i] = '\0';
	return (dest);
}


/**
* _strsplit - split string in tab_word
* @str: string
* @c: word delimiter
*
* Return: tab of word or NULL
*/

char **_strsplit(char *str, int c)
{
	unsigned int i, j, k;
	unsigned int word = 0;
	char **tab_word;

	for (i = 0; str[i] != '\0'; i++)
		if (str[i] == c)
			word++;
	if (str == NULL || strlen(str) == 0 || i == word)
		return (NULL);
	tab_word = malloc(sizeof(char *) * (word + 4));
	if (tab_word == NULL)
		return (NULL);
	k = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] && str[i + j] != c)
			j++;
		if (j == 0)
		{
			i++;
			continue;
		}
		tab_word[k] = malloc(sizeof(char) * strlen(str) + 4);
		if (tab_word[k] == NULL)
		{
			for (j = 0; j < k; j++)
				free(tab_word[j]);
			free(tab_word);
			return (NULL);
		}
		for (j = 0; str[i + j] && str[i + j] != c; j++)
			;
		_strncpy(*(tab_word + k), (str + i), j);
		k++;
		i += j;
	}
	tab_word[k] = NULL;
	return (tab_word);
}

/**
* clean_line - clean tab and new line
* @line: line of file
* Return: 0 if succes, 1 if is a comment
*/
int clean_line(char *line)
{
	unsigned int i;
	unsigned int size;

	size = strlen(line) - 1;
	if (line[size] == '\n')
		line[size] = '\0';

	for (i = 0; line[i] != '\0'; i++)
		if (line[i] == '\t')
			line[i] = ' ';
	if (line[0] == '#')
		return (1);
	return (0);
}
