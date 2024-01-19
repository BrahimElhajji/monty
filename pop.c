#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: pointer to the stack
 * @line_number: line number in Monty file where pop was called
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	top = *stack;
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(b.file);
		free(b.cont);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;

	if (*stack)
		(*stack)->prev = NULL;

	free(top);
}
