#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @stack: pointer to stack
 * @line_number: line_number
 * Return: always nothing
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int t, nx;

	tmp = *stack;
	if ((*stack) && (*stack)->next)
	{
		t = (*stack)->n;
		nx = (*stack)->next->n;
		t += nx;
		tmp = *stack;
		(*stack) = (*stack)->next;
		(*stack)->prev = NULL;
		(*stack)->n = t;
		free(tmp);
	}
	else
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		global_command.error = 1;
	}
}
