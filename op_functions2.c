#include "monty.h"
#include <ctype.h>

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

	for (; aux; aux = aux->next)
		i++;
	aux = *pila;
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		gv.n = 1;
		return;
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

/**
 * sub - subtracts the top element of the stack from
 * the second top element of the stack
 * @pila: struct stack_t (stack)
 * @line_number: int (number of the instruction line)
 *
 * Return: void
 */

void sub(stack_t **pila, unsigned int line_number)
{
	int sb = 0, i = 0;
	stack_t *aux = *pila;

	for (; aux; aux = aux->next)
		i++;
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		gv.n = 1;
		return;
	}
	aux = *pila;
	sb = aux->next->n - aux->n;
	aux = aux->next;
	pop(pila, line_number);
	aux->n = sb;
}

/**
 * _div - divides the second top element of the
 * stack by the top element of the stack
 * @pila: struct stack_t (stack)
 * @line_number: int (number of the instruction line)
 *
 * Return: void
 */

void _div(stack_t **pila, unsigned int line_number)
{
	int dv = 0, i = 0;
	stack_t *aux = *pila;

	for (; aux; aux = aux->next)
		i++;
	aux = *pila;
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		gv.n = 1;
		return;
	}
	if (aux->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		gv.n = 1;
		return;
	}
	dv = aux->next->n / aux->n;
	aux = aux->next;
	pop(pila, line_number);
	aux->n = dv;
}

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
		gv.n = 1;
		return;
	}
	aux = *pila;
	mul = aux->n * aux->next->n;
	aux = aux->next;
	pop(pila, line_number);
	aux->n = mul;
}
