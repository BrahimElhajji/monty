#include "monty.h"

/**
 * nop - doesn't do anything
 * @stack: pointer to pointer to the head of stack
 * @line_number: line number in Monty file where nop was called
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
