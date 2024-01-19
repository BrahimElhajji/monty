#include "monty.h"
/**
 * pint - prints the top
 * @stack: pointer to pointer to the stack head
 * @line_number: counter
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(b.file);
		free(b.cont);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
