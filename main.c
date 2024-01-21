#include "monty.h"

/**
 * main - monty code interpreter
 * @argc: argument counter
 * @argv: argument vector
 * Return: always 0
 */

Monty_G_t Monty_G;
FILE *file;

int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;
	instruction_t instructions[] = {{"push", push},
		{"pall", pall}, {"pint", pint},};
	size_t num_instructions = sizeof(instructions) / sizeof(instructions[0]);

	if (argc != 2)
	{
		error();
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		file_open_error(argv[1]);
		return (EXIT_FAILURE);
	}

	execute(file, &stack, instructions, num_instructions);
	fclose(file);
	free_stack(stack);

	return (EXIT_SUCCESS);
}
