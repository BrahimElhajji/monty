#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: pointer to pointer to the head of stack
 * @line_number: line number in Monty file where pstr was called
 */
void pstr(stack_t **stack, unsigned int line_number)
{

	stack_t *current;

	current = *stack;

	while (current != NULL && current->n != 0 && current->n >= 0 && current->n <= 127)
	{
		putchar(current->n);
		current = current->next;
	}
	(void) line_number;

	putchar('\n');
}
