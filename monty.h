#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/**
 *  * struct stack_s - doubly linked list representation of a stack (or queue)
 *   * @n: integer
 *    * @prev: points to the previous element of the stack (or queue)
 *     * @next: points to the next element of the stack (or queue)
 *      *
 *       * Description: doubly linked list node structure
 *        * for stack, queues, LIFO, FIFO
 *         */
typedef struct stack_s
{
		int n;
			struct stack_s *prev;
				struct stack_s *next;
} stack_t;

/**
 *  * struct instruction_s - opcode and its function
 *   * @opcode: the opcode
 *    * @f: function to handle the opcode
 *     *
 *      * Description: opcode and its function
 *       * for stack, queues, LIFO, FIFO
 *        */
typedef struct instruction_s
{
		char *opcode;
			void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct Monty_G_s
{
		char g_value[100];

} Monty_G_t;

extern Monty_G_t Monty_G;
extern FILE *file;

void error(void);
void file_open_error(const char *filename);
void unknown_error(unsigned int line_number, const char *opcode);
void malloc_error(void);
void free_stack(stack_t *stack);
void execute(FILE *file, stack_t **stack, instruction_t instr[], size_t num_instr);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);


#endif
