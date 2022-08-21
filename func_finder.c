#include "monty.h"

/**
 * func_finder - get the according function
 * @word: string (format)
 *
 * Return: struct instruction_t with the accord function
 */

instruction_t func_finder(char *word)
{
	instruction_t func[] = {
		{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add}, {"nop", nop},
		{"sub", sub}, {"div", _div}, {"mul", mul},
		{"mod", mod}, {"pchar", pchar}, {"pstr", pstr},
		{"rotl", rotl}, {"rotr", rotr}, {NULL, NULL}
	};
	int i = 0;

	while (func[i].opcode)
	{
		if (strcmp(func[i].opcode, word) == 0)
			return (func[i]);
		i++;
	}
	return (func[i]);
}
