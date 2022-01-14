#include "monty.h"

/**
* pstr - prints string on the stack
* @stack: top of the stack
* @line_number: line of file
*
*/

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void)line_number;
	if (tmp == NULL)
	{
		putchar('\n');
		return;
	}

	while (isprint(tmp->n) && tmp != NULL)
	{
		putchar(tmp->n);
		tmp = tmp->next;
	}
	putchar('\n');
}
