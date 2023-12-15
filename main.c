#include "monty.h"

int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	/* Define opcode-function mapping */
	/* instruction_t instructions[] = { */
	/*	{"push", push}, */
	/*	{"pall", pall}, */
	/*	{NULL, NULL} */
	/* }; */

	/* Checking and opening the file */
	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* Initialize the stack */
	/* stack_t *stack = NULL; */

	parser(file, &stack);

	/* Close and exit the program successfully */
	fclose(file);
	return (EXIT_SUCCESS);
}
