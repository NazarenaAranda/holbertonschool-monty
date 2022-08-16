#include "monty.h"

instruction_t func_finder(char *word)
{
    instruction_t func[] = {
        {"push", push}, {"pint", pint}, {NULL, NULL}
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
