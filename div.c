#include "monty.h"

/**
 * _div - divides the top two elements of the stack.
 * @stack: pointer to stack
 * @line_number: line_number
 * Return: always nothing
 */

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int t, nx;

	tmp = *stack;
	if ((*stack) && (*stack)->next)
	{
		if ((*stack)->n == 0)
		{
			fprintf(stderr, "L%u: division by zero,\n", line_number);
			global_command.error = 1;
		}
		else
		{
		t = (*stack)->n;
		nx = (*stack)->next->n;
		t /= nx;
		tmp = *stack;
		(*stack) = (*stack)->next;
		(*stack)->prev = NULL;
		(*stack)->n = nx;
		free(tmp);
		}
	}
	else
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		global_command.error = 1;
	}
}
