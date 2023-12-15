#include "monty.h"

void parser(FILE *file, stack_t **stack)
{
	char line[100];
	unsigned int line_number = 0;
	size_t len;
	char *token;
	char *opcode;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	while (fgets(line, sizeof(line), file) != NULL)
	{
		/* remove newlinw */
		len = strlen(line);

		/* newline is removed here */
		if (len > 0 && line[len - 1] == '\n')
		{
			line[len - 1] = '\0';
		}

		/* tokenize character */
		token = strtok(line, " \t\n");

		/* character is being tokenized */
		if (token == NULL)
		{
			/* Empty line, skip to the next iteration */
			continue;
        	}

		/* Extract opcode */
		opcode = token;
		/* printf("Extracted opcode: <%s>\n", opcode); */

		if (strcmp(opcode, instructions[0].opcode) != 0 &&
			strcmp(opcode, instructions[1].opcode) != 0 &&
			strcmp(opcode, instructions[2].opcode) != 0 &&
			strcmp(opcode, instructions[3].opcode) != 0 &&
			strcmp(opcode, instructions[4].opcode) != 0 &&
			strcmp(opcode, instructions[5].opcode) != 0 &&
			strcmp(opcode, instructions[6].opcode) != 0)
		{
			printf("L%u: unknown instruction <%s>\n", line_number, opcode);
		}

		/* Execute the instruction */
		exec(instructions, stack, opcode, line_number);
		line_number++;
	}
}
