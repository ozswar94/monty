#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "monty.h"


/**
* monty - interpreteur monty
* @pathname: name of file
*
*/
void monty(char *pathname)
{
	FILE *m_file;
	unsigned int line_number = 1;
	size_t len_line = 0;
	char *line = NULL;
	stack_t *m_stack = NULL;

	m_file =  fopen(pathname, "r");
	if (m_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", pathname);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		if (getline(&line, &len_line, m_file) == EOF)
		{
			free(line);
			free_stack(m_stack);
			fclose(m_file);
			return;
		}
		clean_line(line);
		global_command.line = _strsplit(line, ' ');
		if (global_command.line == NULL)
		{
			continue;
			line_number++;
		}
		check_instruction(&m_stack, line_number);
		if (global_command.error)
		{
			free_stack(m_stack);
			free(line);
			free_dptr(global_command.line);
			fclose(m_file);
			exit(EXIT_FAILURE);
		}
		free_dptr(global_command.line);
		line_number++;
	}
}


/**
* check_instruction - interpreteur monty
* @m_stack: ptr top of stack
* @line_number: number line of file
*
*/
void check_instruction(stack_t **m_stack, unsigned int line_number)
{
	global_command.error = 0;
	int i = 0;
	instruction_t instruct[] = {
		{_strdup("push"), push},
		{_strdup("pall"), print_all},
		{NULL, NULL},
	};


	while (instruct[i].opcode != NULL)
	{
		if (strcmp(global_command.line[0], instruct[i].opcode) == 0)
		{
			instruct[i].f(m_stack, line_number);
			break;
		}
		i++;
	}

	if (instruct[i].opcode == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
							line_number, global_command.line[0]);
		global_command.error = 1;
	}
	free_instruct_op(instruct);
}

/**
* free_instruct_op - free str on tab instruct
* @instruct: tab of strcut instruct
*
*/
void free_instruct_op(instruction_t *instruct)
{
	int i = 0;

	while (instruct[i].opcode != NULL)
	{
		free(instruct[i].opcode);
		i++;
	}
	instruct = NULL;
}
