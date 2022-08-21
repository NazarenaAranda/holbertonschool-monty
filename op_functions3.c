#include "monty.h"
#include <ctype.h>

/**
 * mul - multiplies the second top element of the
 * stack with the top element of the stack
 * @pila: struct stack_t (stack)
 * @line_number: int (number of the instruction line)
 *
 * Return: void
 */

void mul(stack_t **pila, unsigned int line_number)
{
	int mul = 0, i = 0;
	stack_t *aux = *pila;

	for (; aux; aux = aux->next)
		i++;
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	aux = *pila;
	mul = aux->n * aux->next->n;
	aux = aux->next;
	pop(pila, line_number);
	aux->n = mul;
}

/**
 * mod - computes the rest of the division of the second top element of the
 * stack by the top element of the stack
 * @pila: struct stack_t (stack)
 * @line_number: int (number of the instruction line)
 *
 * Return: void
 */

void mod(stack_t **pila, unsigned int line_number)
{
	int mod = 0, i = 0;
	stack_t *aux = *pila;

	for (; aux; aux = aux->next)
		i++;
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		gv = 1;
	}
	aux = *pila;
	if (aux->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		gv = 1;
		return;
	}
	mod = aux->next->n % aux->n;
	aux = aux->next;
	pop(pila, line_number);
	aux->n = mod;
}
