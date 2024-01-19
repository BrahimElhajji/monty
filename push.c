#include "monty.h"

/**
 * push - add node to the stack
 * @stack: pointer to pointer to the stack head
 * @line_number: line_number
 * Return: no return
 */
void push(stack_t **stack, unsigned int line_number)
{
	int n;

	if (b.arg)
	{
		char *endptr;

		n = strtol(b.arg, &endptr, 10);

		if (*endptr != '\0' && !isspace((unsigned char)*endptr))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(b.file);
			free(b.cont);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(b.file);
		free(b.cont);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	if (b.lif == 0)
		new_node(stack, n);
	else
		new_queue(stack, n);
}
