#include "monty.h"

void error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
}

void file_open_error(const char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
}

void unknown_error(unsigned int line_number, const char *opcode)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
