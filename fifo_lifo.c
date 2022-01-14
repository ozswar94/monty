#include "monty.h"

/**
* lifo - push into stack Last IN First OUT
* @stack: the list
* @line_number: line number for error
*
*/
void lifo(stack_t **stack, unsigned int line_number)
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
	new_element->next = *stack;
	if (*stack)
		(*stack)->prev = new_element;
	*stack = new_element;
}

/**
* fifo - push into stack First IN First OUT
* @queue: the list
* @line_number: line number for error
*
*/
void fifo(stack_t **queue, unsigned int line_number)
{
	stack_t *new_element = NULL;
	stack_t *tmp;

	new_element = malloc(sizeof(stack_t));
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
	if (*queue == NULL)
	{
		new_element->next = NULL;
		new_element->prev = NULL;
		*queue = new_element;
		return;
	}
	tmp = *queue;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_element;
	new_element->prev = tmp;
}

/**
* stack - opcode for stack mode
* @stack: the list
* @line_number: line number for error
*
*/
void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	global_command.flag = 1;
}

/**
* queue - opcode for queue mode
* @stack: the list
* @line_number: line number for error
*
*/
void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	global_command.flag = 2;
}
