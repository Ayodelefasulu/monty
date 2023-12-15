#include "monty.h"

/**
 * mod_op - Computes the remainder of the division of the second top element
 *##   by the top element of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void mod_op(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number); /* Remove the top element */
}
