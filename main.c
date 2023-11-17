#include "main.h"

stack_t *head = NULL;

int main(int argc, char *argv[])
{
    char *text = NULL, *str_1, *str_2;
    int line_number, status = 0;
    size_t len = 0;
    FILE *file;


    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    file = fopen(argv[1], "r");

    if (argv[1] == NULL || file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        free_nodes();
        exit(EXIT_FAILURE);
    }

    for (line_number = 1; getline(&text, &len, file) != -1; line_number++)
    {
        if (text == NULL)
        {
            fprintf(stderr, "Error: malloc failed\n");
            free_nodes();
            exit(EXIT_FAILURE);
        }
        str_1 = strtok(text, DELIM);
        if (str_1 == NULL)
        {
            continue;
        }
        str_2 = strtok(NULL, DELIM);

        if (strcmp(str_1, "stack") == 0)
            status = 0;
        if (strcmp(str_1, "queue") == 0)
            status = 1;

        find_func(str_1, str_2, line_number, status);
    }


    free(text);
    fclose(file);
    free_nodes();
    return (0);
}