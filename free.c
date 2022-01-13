#include "monty.h"

/**
* free_stack - free list
* @head: head of list
*
*/

void free_stack(stack_t *head)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
* free_dptr - free a pointer to pointer
* @ptr: pointer
*
*/
void free_dptr(char **ptr)
{
	int i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}
