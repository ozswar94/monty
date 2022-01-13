#include "monty.h"

/**
 * pop - remove the top element of the stack
 * @stack: pointer to stack
 * @line_number: line_number
 * Return: always nothing
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *pop;

	pop = *stack;
	if (pop)
	{
		*stack = (*stack)->next;
		free(pop);
	}
	else
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		global_command.error = 1;
	}
}
