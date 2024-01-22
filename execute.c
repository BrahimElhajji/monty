#include "monty.h"

/**
 * execute - Execute instr from a file on a stack
 * @file: Pointer to the file containing instr
 * @stack: Pointer to pointer to the stack head
 * @instr: Array of instruction structures
 * @num_instr: Number of instr in the array.=
 */

void execute(FILE *file, stack_t **stack, instruction_t instr[], size_t num_instr)
{
	char opcode[100], *fmt = "L%d: %s %s\n";
	unsigned int line_number = 0, i;
	size_t offset;
	int value;

	while (fgets(opcode, sizeof(opcode), file) != NULL)
	{
		line_number++;

		offset = 0;
		while (isspace(opcode[offset]))
			offset++;

		strtok(opcode + offset, "\n");
		if (opcode[offset] == '#' || opcode[offset] == '\0')
			continue;

		for (i = 0; i < num_instr; i++)
		{
			if (strncmp(opcode + offset, instr[i].opcode, strlen(instr[i].opcode)) == 0)
			{
				if (strcmp(instr[i].opcode, "push") == 0)
				{
					if (sscanf(opcode + offset + strlen(instr[i].opcode), " %d", &value) != 1)
					{
						fprintf(stderr, fmt, line_number, "usage:", "push integer");
						fclose(file);
						free_stack(*stack);
						exit(EXIT_FAILURE);
					}
					sprintf(Monty_G.g_value, "%d", value);
				}
				instr[i].f(stack, line_number);
				break;
			}
		}
		if (i == num_instr)
		{
			unknown_error(line_number, opcode + offset);
			fclose(file);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
}
