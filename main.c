#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

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
