#include "main.h"

void Queue(stack_t **new_node, __attribute__((unused)) unsigned int ln)
{
    stack_t *tmp;

    if (new_node == NULL || *new_node == NULL)
        exit(EXIT_FAILURE);
    if (head == NULL)
    {
        head = *new_node;
        return;
    }
    tmp = head;
    while (tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = *new_node;
    (*new_node)->prev = tmp;
}

void push_t(stack_t **new_node, __attribute__((unused)) unsigned int ln)
{
    if (new_node == NULL || *new_node == NULL)
    {
        exit(EXIT_FAILURE);
    }

    (*new_node)->next = head;
    if (head != NULL)
    {
        head->prev = *new_node;
    }
    head = *new_node;
    (*new_node)->prev = NULL;
}

void pall_t(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;
    (void)line_number;
    if (stack == NULL || *stack == NULL)
    {
        exit(EXIT_FAILURE);
    }

    for (tmp = *stack; tmp != NULL; tmp = tmp->next)
    {
        printf("%d\n", tmp->data);
    }
}

void pint_t(stack_t **stack, unsigned int line_number)
{
    if (stack == NULL || *stack == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        return;
    }
    printf("%d\n", (*stack)->data);
}

void pop_t(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;
    if (stack == NULL || *stack == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        return;
    }

    tmp = *stack;
    *stack = tmp->next;
    if (*stack != NULL)
    {
        (*stack)->prev = NULL;
    }
    free(tmp);
}

void nop_t(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}

void swap_t(stack_t **stack, unsigned int line_number)
{
    stack_t *top;
    stack_t *next_node;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, "swap");
        return;
    }

    top = *stack;
    next_node = top->next;

    top->prev = next_node;
    top->next = next_node->next;
    if (next_node->next != NULL)
    {
        next_node->next->prev = top;
    }
    next_node->next = top;
    next_node->prev = NULL;

    *stack = next_node;
}

void add_t(stack_t **stack, unsigned int line_number)
{
    stack_t *top;
    stack_t *next_node;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, "add");
        return;
    }

    top = *stack;
    next_node = top->next;

    next_node->data += top->data;

    *stack = next_node;
    free(top);
    next_node->prev = NULL;
}

void sub_t(stack_t **stack, unsigned int line_number)
{
    stack_t *top;
    stack_t *next_node;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, "sub");
        return;
    }

    top = *stack;
    next_node = top->next;

    next_node->data -= top->data;

    *stack = next_node;
    free(top);
    next_node->prev = NULL;
}

void div_tt(stack_t **stack, unsigned int line_number)
{
    stack_t *top;
    stack_t *next_node;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, "div");
        return;
    }

    top = *stack;
    next_node = top->next;

    if (top->data == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        return;
    }

    next_node->data /= top->data;

    *stack = next_node;
    free(top);
    next_node->prev = NULL;
}
