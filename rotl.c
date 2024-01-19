#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @stack: pointer to pointer to the head of stack
 * @line_number: line number in Monty file where rotl was called
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *first;

	first = *stack;

	if (first != NULL && first->next != NULL)
	{
		*stack = first->next;
		first->next->prev = NULL;

		while (first->next != NULL)
			first = first->next;

		first->next = first;
		first->prev = NULL;
	}

	(void)line_number;
}
