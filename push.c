#include "monty.h"

/**
* push - push into list
* @head: head of list
* @line_number: line error
*
*/

void push(stack_t **head, unsigned int line_number)
{
	if (global_command.flag == 1)
		lifo(head, line_number);
	else
		fifo(head, line_number);
}
