#include "monty.h"

/**
 * stack - Sets the format of the data to a stack (LIFO).
 * @stack: Pointer to pointer to the stack head
 * @line_number: Line number of the instruction
 */

void my_stack(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
}

/**
 * queue - Sets the format of the data to a queue (FIFO).
 * @stack: Pointer to pointer to the stack head
 * @line_number: Line number of the instruction
 */

void my_queue(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	stack_t *last;

	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		current = *stack;
		last = *stack;

		while (last->next != NULL)
		{
			last = last->next;
		}

		*stack = current->next;
		current->next = NULL;
		last->next = current;
	}
}
