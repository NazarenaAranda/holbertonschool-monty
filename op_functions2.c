#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @pila: struct stack_t (stack)
 * @line_number: int (number of the instruction line)
 *
 * Description: If the stack contains less than two
 * elements, print the error message
 *
 * Return: void
 */

void add(stack_t **pila, unsigned int line_number)
{
	int sum = 0, i = 0;
	stack_t *aux = *pila;

	if (!aux)
		return;
	for (; aux; aux = aux->next)
		i++;
	aux = *pila;
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = aux->n + aux->next->n;
	aux = aux->next;
	pop(pila, line_number);
	aux->n = sum;
}

/**
 * nop - doesn't do anything
 * @pila: struct stack_t (stack)
 * @line_number: int (number of the instruction line)
 *
 * Return: void
 */

void nop(stack_t **pila, unsigned int line_number)
{
	(void) pila;
	(void) line_number;
}
