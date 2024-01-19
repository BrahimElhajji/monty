#include "monty.h"

/**
 * new_queue - function that add a new queue
 * @stack: pointer to pointer to the head of the nodes
 * @n: an integer
 */

void new_queue(stack_t **stack, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	stack_t *temp = *stack;

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = NULL;

	if (*stack == NULL)
	{
		new_node->prev = NULL;
		*stack = new_node;
		return;
	}

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = new_node;
	new_node->prev = temp;
}
