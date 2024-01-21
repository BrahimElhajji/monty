#include "monty.h"

/**
 * execute - Execute instructions from a file on a stack
 * @file: Pointer to the file containing instructions
 * @stack: Pointer to pointer to the stack head
 * @instructions: Array of instruction structures
 * @num_instructions: Number of instructions in the array.=
 */
void execute(FILE *file, stack_t **stack, instruction_t instructions[], size_t num_instructions)
{
	char opcode[100], *fmt = "L%d: %s %s\n";
	unsigned int line_number = 0, i;

	while (fgets(opcode, sizeof(opcode), file) != NULL)
	{
		line_number++;
		strtok(opcode, "\n");

		if (opcode[0] == '#')
			continue;

		for (i = 0; i < num_instructions; i++)
		{
			if (strncmp(opcode, instructions[i].opcode, strlen(instructions[i].opcode)) == 0)
			{
				if (strcmp(instructions[i].opcode, "push") == 0)
				{
					int value;

					if (sscanf(opcode + strlen(instructions[i].opcode), " %d", &value) != 1)
					{
						fprintf(stderr, fmt, line_number, "usage:", "push integer");
						fclose(file);
						free_stack(*stack);
						exit(EXIT_FAILURE);
					}

					sprintf(Monty_G.g_value, "%d", value);
				}

				instructions[i].f(stack, line_number);
				break;
			}
		}

		if (i == num_instructions)
		{
			unknown_error(line_number, opcode);
			fclose(file);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
}
