#include "monty.h"

/**
 * execute - executes the opcode
 * @stack: head linked list - stack
 * @counter: line_counter
 * @file: pointer to the Monty file
 * @content: line content
 * Return: no return
 */

char *strdup_custom(const char *str)
{
	char *dup_str = NULL;
	size_t len;

	if (str == NULL)
		return NULL;

	len = strlen(str);

	dup_str = malloc(len + 1);

	if (dup_str == NULL)
		return NULL;

	memcpy(dup_str, str, len);
	dup_str[len] = '\0';

	return dup_str;
}

int exec(char *cont, stack_t **stack, unsigned int c, FILE *file)
{
	instruction_t opst[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
	};

	unsigned int i = 0;
	char *op = strtok(cont, " \n\t");

	// Replace '\r' with '\0' to handle Windows line endings
	char *newline_char = strchr(cont, '\r');
	if (newline_char != NULL)
	{
		*newline_char = '\0';
	}

	if (op && op[0] == '#')
		return (0);

	char *arg_copy = strtok(NULL, " \n\t");
	if (arg_copy)
		b.arg = strdup_custom(arg_copy);
	else
		b.arg = NULL;


	while (opst[i].opcode && op)
	{

		if (strcmp(op, opst[i].opcode) == 0)
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
		exit(EXIT_FAILURE);
	}

	free(arg_copy);

	return (1);
}

