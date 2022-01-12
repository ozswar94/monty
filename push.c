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
	int n;
	char *token;
	stack_t *new_element = NULL;

	new_element = malloc(sizeof(stack_t));
	if (new_element == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*head);
		return;
	}

	token = strtok(NULL, " \t\n");
	if (token[0] == '0' && strlen(token) == 1)
		n = 0;
	else
	{
		n = atoi(token);
		if (n == 0)
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			free_stack(*head);
			return;
		}
	}
	new_element->n = n;
	new_element->prev = NULL;
	new_element->next = *head;
	if (*head != NULL)
		(*head)->prev = new_element;
	*head = new_element;
}
