#include "monty.h"

extern char *vg;

int main(int argc, char *argv[])
{
    instruction_t ins;
    stack_t *pila = NULL;
    int i = 0, j = 0;
    FILE *stream;
    size_t size = 0;
    char *buf = NULL, *tok = NULL, **arr = NULL, *word;

    if (argc != 2)
        exit(EXIT_FAILURE);
    stream = fopen(argv[1], "r");
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
                vg = tok;
                arr[i] = tok;
            }
        }
        ins = func_finder(arr[0]);
        if (!ins.f)
            exit(EXIT_FAILURE);
        (*(ins.f))(&pila, j);
    }
    return (0);
}
