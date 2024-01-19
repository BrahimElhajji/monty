#include "monty.h"

/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void push(stack_t **head, unsigned int counter)
{
	int n;

	if (b.arg)
	{
		char *endptr;
		n = strtol(b.arg, &endptr, 10);

		if (*endptr != '\0' && !isspace((unsigned char)*endptr))
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(b.file);
			free(b.cont);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
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
