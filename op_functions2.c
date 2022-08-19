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
		exit(EXIT_FAILURE);
	}
	aux = *pila;
	sb = aux->n - aux->next->n;
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
		exit(EXIT_FAILURE);
	}
	if (aux->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	dv = aux->next->n / aux->n;
	aux = aux->next;
	pop(pila, line_number);
	aux->n = dv;
}

/**
 * valid_number - checks if the string only contains digit chars
 * @tok: string
 *
 * Return: 1 if the string only contain digits, otherwise 0
 */

int valid_number(char *tok)
{
	int i = 0;

	if (!tok)
		return (0);
	for (; tok[i]; i++)
	{
		if (tok[i] == '-' || tok[i] == '+')
			continue;
		if (isdigit(tok[i]) == 0)
			return (0);
	}
	return (1);
}
