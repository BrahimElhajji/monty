#include "monty.h"

/**
 * push - add node to the stack
 * @stack: pointer to pointer to the stack head
 * @line_number: the number of lines
 * Return: no return
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	int value;

	if (!Monty_G.g_value || !isdigit(*Monty_G.g_value))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	value = atoi(Monty_G.g_value);
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		malloc_error();
		fclose(file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}
