#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

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
