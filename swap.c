#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to pointer to the head of stack
 * @line_number: line number in Monty file where swap was called
 */

void swap(stack_t **stack, unsigned int line_number)
{

	stack_t *first;
	stack_t *second;

	first = *stack;
	second = (*stack)->next;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(b.file);
		free(b.cont);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;

	*stack = second;

	if (first->next)
		first->next->prev = first;
}
