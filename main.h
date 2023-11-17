#ifndef MAIN_H
#define MAIN_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#define DELIM "$ \t\n"

typedef struct stack_s
{
    int data;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

void free_nodes(void);
stack_t *create_node(int n);
void push_t(stack_t **new_node, __attribute__((unused)) unsigned int ln);
void Queue(stack_t **new_node, __attribute__((unused)) unsigned int ln);
void pall_t(stack_t **stack, unsigned int line_number);
void find_func(char *str_1, char *str_2, int line_number, int status);
void call_fun(op_func func, char *str_1, char *str_2, int line_number, int status);
void pint_t(stack_t **stack, unsigned int line_number);
void pop_t(stack_t **stack, unsigned int line_number);
void nop_t(stack_t **stack, unsigned int line_number);
void swap_t(stack_t **stack, unsigned int line_number);
void add_t(stack_t **stack, unsigned int line_number);
void sub_t(stack_t **stack, unsigned int line_number);
void div_tt(stack_t **stack, unsigned int line_number);

#endif
