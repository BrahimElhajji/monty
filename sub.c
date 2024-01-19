#include "monty.h"

/**
 * sub - subtracts the top element of the stack from the second top element
 * @stack: pointer to pointer to the head of stack
 * @line_number: line number in Monty file where sub was called
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(b.file);
		free(b.cont);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}
