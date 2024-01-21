#include "monty.h"

/**
 *  * free_stack - Frees nodes in the stack.
 *   *@stack: pointer to the stack head
 *    */

void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
