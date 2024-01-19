#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @stack: pointer to pointer to the head of stack
 * @line_number: line number in Monty file where rotr was called
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last;

	last = *stack;

	if (last != NULL && last->next != NULL)
	{
		while (last->next != NULL)
			last = last->next;

		last->prev->next = NULL;
		last->prev = NULL;
		last->next = *stack;
		(*stack)->prev = last;
		*stack = last;
	}

	(void)line_number;
}
