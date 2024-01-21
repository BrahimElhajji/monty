#include "monty.h"

/**
 * push - entry point
 * @stack: stack
 * @line_number: counter
 */

void push(stack_t **stack, unsigned int line_number)
{
	size_t len;
	char *endptr;
	long num;

	if (b.arg == NULL || *b.arg == '\0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(b.file);
		free(b.cont);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	while (isspace((unsigned char)*b.arg))
		b.arg++;

	
	len = strlen(b.arg);

	while (len > 0 && isspace((unsigned char)b.arg[len - 1]))
	{
		b.arg[len - 1] = '\0';
		len--;
	}

	num = strtol(b.arg, &endptr, 10);

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
