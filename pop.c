#include <stdio.h>
#include <stdlib.h>

/**
 * pop - remove the top element of the stack
 * @stack: pointer to stack
 * @line_number: line_number
 * Return: always nothing
 */

void *pop(stack_t **stack, unsigned int line_number)
{
	stack_t *pop;

	pop = *stack;
	if (pop)
	{
		while (pop)
			pop = pop->next;
		pop->prev->next = NULL;
		free(pop);
	}
	else
	{
		printf("L<%d>: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
}
