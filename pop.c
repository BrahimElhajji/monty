#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: pointer to pointer to the stack head
 * @line_number: the number of lines
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
		fclose(file);
	}

	temp = *stack;
	*stack = (*stack)->next;

	if (*stack)
		(*stack)->prev = NULL;

	free(temp);
}
