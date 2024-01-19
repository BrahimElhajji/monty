#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: pointer to pointer to the head of stack
 * @line_number: line number in Monty file where add was called
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;

	first = *stack;
	second = (*stack)->next;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(b.file);
		free(b.cont);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	second->n += first->n;
	*stack = second;
	free(first);
	if (second->next)
		second->next->prev = second;
}
