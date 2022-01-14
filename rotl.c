#include "monty.h"

/**
 * rotl - rotates the stack to the top.
 * @stack: pointer to stack
 * @line_number: line_number
 * Return: always nothing
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *last, *cln, *tmp;
	(void)line_number;

	last = *stack;
	cln = *stack;
	while (last->next)
		last = last->next;
	tmp = cln->next;
	cln->next->prev = NULL;
	cln->prev = last;
	last->next = cln;
	cln->next = NULL;
	(*stack) = tmp;
}
