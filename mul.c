#include "monty.h"

/**
 * mul - multiplies the second top element of the stack with the top element
 * @stack: pointer to pointer to the head of stack
 * @line_number: line number in Monty file where mul was called
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(b.file);
		free(b.cont);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}
