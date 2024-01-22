#include "monty.h"

/**
 * rotl - Rotates the stack to the top.
 * @stack: Pointer to pointer to the stack head
 * @line_number: Line number of the instruction
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *last;
	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		last = *stack;
		while (last->next != NULL)
			last = last->next;

		last->next = *stack;
		*stack = (*stack)->next;
		last->next->next = NULL;
	}
}
