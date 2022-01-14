#include "monty.h"

/**
 * rotr - rotates the stack to the top.
 * @stack: pointer to stack
 * @line_number: line_number
 * Return: always nothing
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last, *cln;
	int counter = 0, t;
	(void)line_number;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		return;
	}
	else
	{
		last = *stack;
		cln = *stack;
		while (last->next)
		{
			last = last->next;
			counter++;
		}
		if (counter == 1)
		{
			t = (*stack)->n;
			(*stack)->n = (*stack)->next->n;
			(*stack)->next->n = t;
		}
		else
		{
			last->prev->next = NULL;
			cln->prev = last;
			last->next = cln;
			last->prev = NULL;
			(*stack) = last;
		}
	}
}
