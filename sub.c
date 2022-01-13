#include "monty.h"

/**
 * sub - subtract the top two elements of the stack.
 * @stack: pointer to stack
 * @line_number: line_number
 * Return: always nothing
 */


void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int t, nx;

	tmp = *stack;
	if ((*stack) && (*stack)->next)
	{
		t = (*stack)->n;
		nx = (*stack)->next->n;
		nx -= t;
		tmp = *stack;
		(*stack) = (*stack)->next;
		(*stack)->prev = NULL;
		(*stack)->n = nx;
		free(tmp);
	}
	else
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		global_command.error = 1;
	}
}
