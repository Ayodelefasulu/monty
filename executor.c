#include "monty.h"
/**
 * exec - The brain box of the interpreter.
 * @instructions: Instructions is linked, mapped with the functions
 * @stack: Double pointer to the top of the stack.
 * @opcode: The monty script operation code.
 * @line_number: Line number in the Monty byte code file.
 */
void exec(instruction_t *instructions, stack_t **stack,
	char *opcode, unsigned int line_number);
void exec(instruction_t *instructions, stack_t **stack,
	char *opcode, unsigned int line_number)
{
	int i;

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "Error: Unknown opcode %s at line %u\n", opcode, line_number);
	exit(EXIT_FAILURE);
}
