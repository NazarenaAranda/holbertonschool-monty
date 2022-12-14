#ifndef monty_h
#define monty_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct gv_s - contains a value to exit if it requires
 * and the mode to queue or stack
 * @n: integer (1 if exit ins neccesary)
 * @mode: integer (1 for queue mode, 0 for stack mode)
 */
typedef struct gv_s
{
	int n;
	int mode;
} gv_t;
extern gv_t gv;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

instruction_t func_finder(char *word);
void push(stack_t **pila, unsigned int line_number);
void pall(stack_t **pila, unsigned int line_number __attribute__((unused)));
void pint(stack_t **pila, unsigned int line_number);
void pop(stack_t **pila, unsigned int line_number);
void swap(stack_t **pila, unsigned int line_number);
void add(stack_t **pila, unsigned int line_number);
void nop(stack_t **pila, unsigned int line_number);
void sub(stack_t **pila, unsigned int line_number);
void _div(stack_t **pila, unsigned int line_number);
void mul(stack_t **pila, unsigned int line_number);
void mod(stack_t **pila, unsigned int line_number);
void pchar(stack_t **pila, unsigned int line_number);
void pstr(stack_t **pila, unsigned int line_number __attribute__((unused)));
void rotl(stack_t **pila, unsigned int line_number __attribute__((unused)));
void rotr(stack_t **pila, unsigned int line_number __attribute__((unused)));
void queue(stack_t **pila, unsigned int line_number);
void stack(stack_t **pila, unsigned int line_number);
void add_node_end(stack_t **pila, stack_t **node);
int valid_number(char *tok);

#endif
