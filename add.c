#include <stdio.h>
#include <stdlib.h>

/**
 * add - adds the top two elements of the stack.
 * @stack: pointer to stack
 * @line_number: line_number
 * Return: always nothing
 */

void *add(stack_t **stack, unsigned int line_number)
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
		p = t + d;
		tmp->n = p;
		tmp->next = NULL;
		free(dlt);
	}
	else
	{
		printf("L<%d>: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
