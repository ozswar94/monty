#include "monty.h"

/**
 * mul - multiplies the top two elements of the stack.
 * @stack: pointer to stack
 * @line_number: line_number
 * Return: always nothing
 */

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *dlt;
	int t, d, p;

	tmp = *stack;
	if (tmp->next)
	{
		while (tmp)
			tmp = tmp->next;
		dlt = tmp;
		tmp = tmp->prev;
		t = tmp->n;
		d = dlt->n;
		p = t * d;
		tmp->n = p;
		tmp->next = NULL;
		free(dlt);
	}
	else
	{
		printf("L<%d>: can't mul, stack too short\n", line_number);
		global_command.error = 1;
	}
}
