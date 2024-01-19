#include "monty.h"

/**
 * pall - function that prints all
 * @stack: pointer to pointer of the head on the nodes
 * @line_number: counter
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	(void) line_number;
}
