#include "monty.h"

/**
 * pall - function that prints all
 * @stack: pointer to pointer of the head on the nodes
 * @line_number: the number of lines
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
