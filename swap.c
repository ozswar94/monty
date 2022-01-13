#include "monty.h"

/**
 * swap - swaps the top two elements of the stack.
 * @stack: pointer to stack
 * @line_number: line_number
 * Return: always nothing
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *swp, *prev;

	tmp = *stack;
	if (tmp)
	{
		while (tmp)
			tmp = tmp->next;
		swp = tmp->prev;
		prev = swp->prev;
		prev->next = tmp;
		tmp->prev = prev;
		tmp->next = swp;
		swp->prev = tmp;
		swp->next = NULL;
	}
	else
	{
		printf("L<%d>: can't swap, stack too short\n", line_number);
		global_command.error = 1;
	}
}
