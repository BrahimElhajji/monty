#include "monty.h"

/**
 *  * validate_push_input - validate input arguments for the push operation
 *   * @stack: stack
 *    * @line_number: counter
 *     */
void push_input(stack_t **stack, unsigned int line_number)
{
	size_t len;
	char *space_pos; 

	space_pos = strchr(b.arg, ' ');
	len = strlen(b.arg);

	if (b.arg == NULL || *b.arg == '\0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(b.file);
		free(b.cont);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if (strlen(b.arg) == 0)
	{
		fprintf(stderr, "L%d: Blank line\n", line_number);
		fclose(b.file);
		free(b.cont);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if (isspace((unsigned char)b.arg[0]))
	{
		fprintf(stderr, "L%d: Spaces before opcode\n", line_number);
		fclose(b.file);
		free(b.cont);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	while (len > 0 && isspace((unsigned char)b.arg[len - 1]))
	{
		b.arg[len - 1] = '\0';
		len--;
	}
	if (space_pos != NULL)
	{
		fprintf(stderr, "L%d: Spaces between opcode and value\n", line_number);
		fclose(b.file);
		free(b.cont);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
