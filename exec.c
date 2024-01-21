#include "monty.h"

/**
 * exec - executes the opcode
 * @cont: line content
 * @stack: head linked list - stack
 * @c: line_counter
 * @file: pointer to the Monty file
 * Return: 1
 */

int exec(char *cont, stack_t **stack, unsigned int c, FILE *file)
{
	instruction_t opst[] = {
		{"push", push}, {"pall", pall}, {"pint", pint},
	};

	char *op = strtok(cont, " \n\t");
	char *newline_char = strchr(cont, '\r');
	char *arg_copy = strtok(NULL, " \n\t");
	unsigned int i = 0;

	if (newline_char != NULL)
		*newline_char = '\0';
	if (op && op[0] == '#')
		return (0);

	b.arg = (arg_copy) ? strdup_custom(arg_copy) : NULL;

	while (opst[i].opcode && op)
	{
		if (!strcmp(op, opst[i].opcode))
		{
			opst[i].f(stack, c);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", c, op);
		fclose(file);
		free(cont);
		free_stack(*stack);
		free(arg_copy);
		exit(EXIT_FAILURE);
	}
	return (1);
}
