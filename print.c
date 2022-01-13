#include "monty.h"

/**
* print_all - print stack
* @head: top of the stack
* @line_number: line of file
*
*/
void print_all(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;
	tmp = *head;
	while (tmp != NULL)
	{
		fprintf(stdout, "%d\n", tmp->n);
		tmp = tmp->next;
	}
}
