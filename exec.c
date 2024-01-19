#include "monty.h"

/**
 * exec - executes the opcode
 * @cont: line content
 * @stack: head linked list - stack
 * @c: line_counter
 * @file: pointer to the Monty file
 * Return: no return
 */
int exec(char *cont, stack_t **stack, unsigned int c, FILE *file)
{
	instruction_t opst[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add}, {"nop", nop}, {"sub", sub},
		{"div", my_div}, {"mul", mul}, {"mod", mod}, {"pchar", pchar},
		{"pstr", pstr}, {"rotl", rotl}, {"rotr", rotr}, {NULL, NULL}
	};

	char *op = strtok(cont, " \n\t");
	char *newline_char = strchr(cont, '\r');
	char *arg_copy = strtok(NULL, " \n\t");
	unsigned int i;

	if (newline_char != NULL)
		*newline_char = '\0';
	if (op && op[0] == '#')
		return (0);

	b.arg = (arg_copy) ? strdup_custom(arg_copy) : NULL;

	for (i = 0; opst[i].opcode; i++)
	{
		if (!strcmp(op, opst[i].opcode))
		{
			opst[i].f(stack, c);
			return (0);
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", c, op);
	fclose(file);
	free(cont);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
