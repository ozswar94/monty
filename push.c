#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
* push - add new element top of the stack
* @head: head of list
* @line_number: line error
*
*/

void push(stack_t **head, unsigned int line_number)
{
	stack_t *new_element = NULL;

	(void)line_number;
	new_element = (stack_t *)malloc(sizeof(stack_t));
	if (new_element == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		global_command.error = 1;
		return;
	}

	if (is_not_number(global_command.line[1]) == 1)
	{
		free(new_element);
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		global_command.error = 1;
		return;
	}

	new_element->n = atoi(global_command.line[1]);
	new_element->prev = NULL;
	new_element->next = *head;
	if (*head)
		(*head)->prev = new_element;
	*head = new_element;
}
