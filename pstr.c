#include "monty.h"

/**
 * pstr - Prints the string starting at the top of the stack.
 * @stack: Pointer to pointer to the stack head
 * @line_number: Line number of the instruction
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
       
	current = *stack;

	(void)line_number;

	while (current != NULL && current->n != 0 && current->n >= 0 && current->n <= 127)
	{
		putchar(current->n);
		current = current->next;
	}

	putchar('\n');
}
