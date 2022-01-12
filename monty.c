#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "monty.h"

void monty(char *pathname)
{
	FILE *m_file;
	unsigned int line_number = 1;
	size_t len_line = 0;
	stack_t *m_stack = NULL;

	m_file =  fopen(pathname, "r");
	if (m_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", pathname);
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		line = NULL;
		if (getline(&line, &len_line, m_file) == EOF)
		{
			free(line);
			free_stack(m_stack);
			return;
		}
		check_instruction(m_stack, line_number);	
		/*if (m_stack == NULL)
		{
			exit(EXIT_FAILURE);
		}*/
		line_number++;
	}
	fclose(m_file);
}

void check_instruction(stack_t *m_stack ,unsigned int line_number)
{
	int i;
	char *token;
	instruction_t instruct[] = {
		{_strdup("push"), push},
		{_strdup("pall"), print_all},
		{NULL, NULL},
	};
	
	i = 0;
	token = strtok(line, " \t\n");
	while (instruct[i].opcode != NULL)
	{
		if (strcmp(instruct[i].opcode, token) == 0)
		{
			instruct[i].f(&m_stack, line_number);
			break;
		}
		i++;
	}
	print_all(&m_stack, line_number);
	if (instruct[i].opcode == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
		free_stack(m_stack);
	}
	free_instruct_op(instruct);
}

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