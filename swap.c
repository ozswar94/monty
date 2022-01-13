#include "monty.h"
/**
 * swap - swaps the top two elements of the stack.
 * @stack: pointer to stack
 * @line_number: line_number
 * Return: always nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if ((*stack) && (*stack)->next)
	{
		tmp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = tmp;
	}
	else
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		global_command.error = 1;
	}
}
