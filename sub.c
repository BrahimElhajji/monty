#include "monty.h"

/**
 * sub - Subtracts the top element of the stack from the second top element
 * @stack: Pointer to pointer to the stack head
 * @line_number: Line number of the instruction
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
		fclose(file);
	}

	(*stack)->next->n -= (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}
