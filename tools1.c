#include "main.h"

void free_nodes(void)
{
    stack_t *tmp;

    if (head == NULL)
        return;

    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

stack_t *create_node(int n)
{
    stack_t *node;

    node = malloc(sizeof(stack_t));
    if (node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
    }
    node->next = NULL;
    node->prev = NULL;
    node->data = n;
    return (node);
}

void find_func(char *str_1, char *str_2, int line_number, int status)
{
    int i;
    int flag = 1;

    instruction_t func_list[] = {
        {"push", push_t},
        {"pall", pall_t},
        {"pint", pint_t},
        {"pop", pop_t},
        {"nop", nop_t},
        {"swap", swap_t},
        {"add", add_t},
        {"sub", sub_t},
        {"div", div_tt},
        /*
        {"mul", mul_nodes},
        {"mod", mod_nodes},
        {"pchar", print_char},
        {"pstr", print_str},
        {"rotl", rotl},
        {"rotr", rotr},*/
        {NULL, NULL}};

    if (str_1[0] == '#')
        return;

    for (i = 0; func_list[i].opcode != NULL; i++)
    {
        if (strcmp(str_1, func_list[i].opcode) == 0)
        {
            call_fun(func_list[i].f, str_1, str_2, line_number, status);
            flag = 0;
        }
    }
    if (flag == 1)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", line_number, str_1);
        free_nodes();
        exit(EXIT_FAILURE);
    }
}

void call_fun(op_func func, char *str_1, char *str_2, int line_number, int status)
{
    stack_t *node;
    int flag;
    int i;

    flag = 1;

    if (strcmp(str_1, "push") == 0)
    {
        if (str_2 == NULL)
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            free_nodes();
            exit(EXIT_FAILURE);
        }

        if (str_2 != NULL && str_2[0] == '-')
        {
            str_2++;
            flag = -1;
        }

        for (i = 0; str_2[i] != '\0'; i++)
        {
            if (isdigit(str_2[i]) == 0)
            {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                free_nodes();
                exit(EXIT_FAILURE);
            }
        }

        node = create_node(atoi(str_2) * flag);

        if (status == 0)
        {
            func(&node, line_number);
        }

        if (status == 1)
        {
            Queue(&node, line_number);
        }
    }
    else
    {
        func(&head, line_number);
    }
}