#include "monty.h"
#include <ctype.h>

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

/**
 * add_node_end - adds a node at the end of the list
 * @pila: stack
 * @node: node to be added
 *
 * Return:void
 */

void add_node_end(stack_t **pila, stack_t **node)
{
	stack_t *aux = *pila;

	(*node)->next = NULL;
	if (!aux)
	{
		*pila = *node;
		(*node)->prev = NULL;
	} else
	{
		while (aux->next)
			aux = aux->next;
		(*node)->prev = aux;
		aux->next = *node;
	}
}
