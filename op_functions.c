#include "monty.h"

/**
 * push - pushes an element to the stack
 * @pila: struct stack_t (stack)
 * @line_number: int (number of the line)
 *
 * Return: void
 */

void push(stack_t **pila, unsigned int line_number)
{
	stack_t *node = NULL;
	char *tok = NULL;

	tok = strtok(NULL, "\t\n ");
	node = malloc(sizeof(stack_t));
	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (atoi(tok) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	node->n = atoi(tok);
	node->prev = NULL;
	if (*pila == NULL)
	{
		node->next = NULL;
		*pila = node;
	} else
	{
		node->next = *pila;
		(*pila)->prev = node;
		*pila = node;
	}
}

/**
 * pall - prints all the values on the stack,
 * starting from the top of the stack
 * @pila: struct stack_t (stack)
 * @line_number: int (number of the line)
 *
 * Return: void
 */

void pall(stack_t **pila, unsigned int line_number __attribute__((unused)))
{
	stack_t *aux = *pila;

	if (!aux)
		return;
	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}

/**
 * pint - prints the value at the top of the stack, followed by a new line
 * @pila: struct stack_t (stack)
 * @line_number: int (number of the line)
 *
 * Return: void
 */

void pint(stack_t **pila, unsigned int line_number)
{
	stack_t *aux = *pila;

	if (!aux)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", aux->n);
}

/**
 * pop - removes the top element of the stack
 * @pila: struct stack_t (stack)
 * @line_number: int (number of the line)
 *
 * Return: void
 */

void pop(stack_t **pila, unsigned int line_number)
{
	stack_t *aux = *pila;

	if (!aux)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*pila = (*pila)->next;
	(*pila)->prev = NULL;
	free(aux);
}

/**
 * swap - swaps the top two elements of the stack
 * @pila: struct stack_t (stack)
 * @line_number: int (number of the line)
 *
 * Return: void
 */

void swap(stack_t **pila, unsigned int line_number)
{
	stack_t *aux = *pila;
	int i = 0, value;

	if (!aux)
		return;
	for (; aux; aux = aux->next)
		i++;
	value = (*pila)->n;
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*pila)->n = (*pila)->next->n;
	(*pila)->next->n = value;
}
