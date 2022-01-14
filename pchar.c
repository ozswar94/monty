#include "monty.h"

/**
* pchar - prints the char at the top of the stack
* @stack: top of the stack
* @line_number: line of file
*
*/

void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		global_command.error = 1;
		return;
	}

	if (isprint((*stack)->n))
		printf("%c\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		global_command.error = 1;
	}
}
