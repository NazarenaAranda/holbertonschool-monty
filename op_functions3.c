#include "monty.h"
#include <ctype.h>

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
		return;
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

/**
 * pchar - prints the char at the top of the stack, followed by a new line
 * @pila: struct stack_t (stack)
 * @line_number: int (number of the instruction line)
 *
 * Return: void
 */

void pchar(stack_t **pila, unsigned int line_number)
{
	stack_t *aux = *pila;

	if (!aux)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		gv = 1;
		return;
	}
	if (aux->n < 32 || aux->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		gv = 1;
		return;
	}
	printf("%c\n", aux->n);
}

/**
 * pstr - prints the string starting at the top
 * of the stack, followed by a new line
 * @pila: struct stack_t (stack)
 * @line_number: int (number of the instruction line)
 *
 * Return: void
 */

void pstr(stack_t **pila, unsigned int line_number __attribute__((unused)))
{
	stack_t *aux = *pila;

	if (!aux)
	{
		printf("\n");
		return;
	}
	while (aux)
	{
		if (aux->n == 0)
			break;
		if (aux->n < 32 || aux->n > 127)
			break;
		printf("%c", aux->n);
		aux = aux->next;
	}
	printf("\n");
}

/**
 * rotl - rotates the stack to the top
 * @pila: struct stack_t (stack)
 * @line_number: int (number of the instruction line)
 *
 * Return: void
 */

void rotl(stack_t **pila, unsigned int line_number __attribute__((unused)))
{
	stack_t *aux = *pila, *p = NULL;
	int i = 1;

	if (!aux)
		return;
	for (; aux->next; aux = aux->next)
		i++;
	if (i < 2)
		return;
	p = aux; /*first element of the stack (last of the list)*/
	aux = *pila;
	*pila = aux->next;
	(*pila)->prev = NULL;
	p->next = aux;
	aux->prev = p;
	aux->next = NULL;
}

/**
 * rotr - rotates the stack to the bottom
 * @pila: struct stack_t (stack)
 * @line_number: int (number of the instruction line)
 *
 * Return: void
 */

void rotr(stack_t **pila, unsigned int line_number __attribute__((unused)))
{
	stack_t *aux = *pila, *p = NULL;
	int i = 1;

	if (!aux)
		return;
	for (; aux->next; aux = aux->next)
		i++;
	if (i < 2)
		return;
	p = aux;
	aux = *pila;
	*pila = p;
	p->prev->next = NULL;
	p->prev = NULL;
	p->next = aux;
}
