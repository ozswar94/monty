#include <stdio.h>
#include <stdlib.h>

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to stack
 * @line_number: line_number
 * Return: always nothing
 */

void *pint(stack_t **stack, unsigned int line_number)
{
	stack_t *pint;

	pint = *stack;
	if (pint)
	{
		while (pint)
			pint = pint->next;
		printf("%d\n", pint->n);
	}
	else
	{
		printf("L<%d>: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
