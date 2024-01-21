#include "monty.h"

/**
 * push - entry point
 * @stack: stack
 * @line_number: counter
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *endptr;
	long num = strtol(b.arg, &endptr, 10);

	push_input(stack, line_number);

	if (*endptr != '\0' && !isspace((unsigned char)*endptr))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(b.file);
		free(b.cont);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	new_node(stack, num);
}
