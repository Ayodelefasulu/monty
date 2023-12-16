#include "monty.h"
/**
 * main - Entry point of the interpreter.
 * @argc: Number of commmand line arguments.
 * @argv: Values of the arguments.
 *
 * Return: Return with an exist code success
 */
int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	/* checking and opening the file */
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
