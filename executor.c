#include "monty.h"

void exec(instruction_t *instructions, stack_t **stack, char *opcode, unsigned int line_number)
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
