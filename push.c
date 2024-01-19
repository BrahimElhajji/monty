#include "monty.h"

/**
 * push - add new node to the stack
 * @head: stack head
 * @line_number: counter
 */
void push(stack_t **head, unsigned int line_number)
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
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(b.file);
		free(b.cont);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	if (b.lif == 0)
		new_node(head, n);
	else
		new_queue(head, n);
}
