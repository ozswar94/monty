#include "monty.h"

/**
* main - clean tab and new line
* @argc: number of argument
* @argv: argument of file
* Return: Always 0
*/
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file");
		return (EXIT_FAILURE);
	}
	monty(argv[1]);
	return (0);
}
