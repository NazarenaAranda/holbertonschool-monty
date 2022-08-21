#include "monty.h"

gv_t gv = {0, 0};

/**
 * freedom - free everything
 * @buf: string of chars (buffer of getline)
 * @pila: stack
 *
 * Return: void
 */

void freedom(char *buf, stack_t **pila)
{
	stack_t *aux = *pila;

	if (buf)
		free(buf);
	while (*pila)
	{
		aux = *pila;
		*pila = (*pila)->next;
		free(aux);
	}
}

/**
 * main - main function
 * @argc: int (amount of arguments)
 * @argv: pointer to an array of pointers (with the arguments)
 *
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	instruction_t ins;
	stack_t *pila = NULL;
	int j = 0;
	FILE *stream;
	size_t size = 0;
	char *buf = NULL, *tok = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	stream = fopen(argv[1], "r");
	if (!stream)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buf, &size, stream) != -1)
	{
		j++;
		tok = strtok(buf, "\n\t $");
		if (!tok)
			continue;
		if (tok[0] == '#')
			continue;
		ins = func_finder(tok);
		if (!ins.f)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", j, tok);
			gv.n = 1;
		}
		else
			(*(ins.f))(&pila, j);
	}
	fclose(stream);
	freedom(buf, &pila);
	if (gv.n == 1)
		exit(EXIT_FAILURE);
	return (0);
}
