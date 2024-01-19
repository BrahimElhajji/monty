#include "monty.h"

/**
 * my_div - divides the second top element of the stack by the top element
 * @stack: pointer to pointer to the head of stack
 * @line_number: line number in Monty file where div was called
 */
void my_div(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL || (*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero or stack too short\n", line_number);
		fclose(b.file);
		free(b.cont);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_number);
}
