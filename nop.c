#include <stdio.h>
#include <stdlib.h>

/**
 * nop - doesn’t do anything.
 * @stack: pointer to stack
 * @line_number: line_number
 * Return: always nothing
 */

void *nop(stack_t **stack, unsigned int line_number)
{
	(void)**stack;
	(void)line_number;
}
