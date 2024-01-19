#include "monty.h"

/**
 * mod - computes the rest of the div of the second top element by the top element
 * @stack: pointer to pointer to the head of stack
 * @line_number: line number in Monty file where mod was called
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL || (*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero or stack too short\n", line_number);
		fclose(b.file);
		free(b.cont);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}
