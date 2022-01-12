#include <stdlib.h>
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
