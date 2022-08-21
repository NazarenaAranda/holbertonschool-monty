#include "monty.h"

/**
 * queue - sets the format of the data to a queue (FIFO)
 * @pila: struct stack_t (stack)
 * @line_number: int (number of the instruction line)
 *
 * Return: void
 */

void queue(stack_t **pila, unsigned int line_number)
{
	(void)pila;
	(void)line_number;
	gv.mode = 1;
}

/**
 * stack - sets the format of the data to a stack (LIFO).
 * This is the default behavior of the program
 * @pila: struct stack_t (stack)
 * @line_number: int (number of the instruction line)
 *
 * Return: void
 */

void stack(stack_t **pila, unsigned int line_number)
{
	(void)pila;
	(void)line_number;
	gv.mode = 0;
}
