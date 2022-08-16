#include "monty.h"

extern char *vg;

void push(stack_t **pila, unsigned int line_number)
{
    stack_t *node = NULL;

    node = malloc(sizeof(stack_t));
    if (!node)
        exit(EXIT_FAILURE);
    if (atoi(vg) == 0)
        exit(EXIT_FAILURE);
    node->n = atoi(vg);
    node->prev = NULL;
    if (pila == NULL)
    {
        node->next = NULL;
        *pila = node;
    } else
        node->next = *pila;
        *pila = node;   
}

void pint(stack_t **pila, unsigned int line_number)
{
    stack_t *aux = *pila;

    if(aux)
        printf("%d\n", aux->n);
}
