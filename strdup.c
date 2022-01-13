#include <stdlib.h>
#include <ctype.h>
#include "monty.h"

/**
* _strdup - create a new string and copy str in the new string
* @str: string
* Return: new string
*/

char *_strdup(char *str)
{
	unsigned int i;
	unsigned int size;
	char *buffer;

	if (str == NULL)
		return (NULL);
	for (size = 0; str[size] != '\0' ; size++)
	;
	buffer = (char *)malloc(sizeof(char) * size + 1);
	if (!buffer)
		return (NULL);

	for (i = 0; i < size; i++)
		buffer[i] = str[i];
	buffer[i] = '\0';
	return (buffer);
}

/**
* is_not_number - check if str is a number
* @num: string number
* Return: 0 Success , 1 if not a number
*/
int is_not_number(char *num)
{
	int i = 0;

	if (num[i] == '-' || num[i] == '+')
		i++;
	while (isdigit(num[i]) && num[i] != '\0')
		i++;

	if (num[i] == '\0')
		return (0);
	return (1);
}
