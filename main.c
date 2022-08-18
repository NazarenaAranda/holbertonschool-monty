#include "monty.h"

char *gv = NULL;

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
	int i = 0, j = 0;
	FILE *stream;
	size_t size = 0;
	char *buf = NULL, *tok = NULL, **arr = NULL, *word = NULL;

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
		i = 0;
		arr = malloc(sizeof(char *) * 3);
		arr[2] = NULL;
		tok = strtok(buf, "\n\t $");
		arr[i] = tok;
		while (tok)
		{
			i++;
			if (i > 1)
			break;
			tok = strtok(NULL, "\n\t $");
			if (tok)
			{
				gv = tok;
				arr[i] = tok;
			}
		}
		ins = func_finder(arr[0]);
		if (!ins.f)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", j, ins.opcode);
			exit(EXIT_FAILURE);
		}
		(*(ins.f))(&pila, j);
		j++;
	}
	fclose(stream);
	freedom(buf, &pila);
	return (0);
}
