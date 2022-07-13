#ifndef STACK_H
#define STACK_H
#include <ADT/types.h>

typedef int element_type;

typedef struct stack
{
    int top;
    int max_size;
    element_type *element;
}stack;

//stack op
status stack_create(stack *s, int max_size);
status stack_destroy(stack *s);
status stack_is_empty(stack *s);
status stack_is_full(stack *s);
status top(stack *s,  element_type *x);
status push(stack *s, element_type x);
status pop(stack *s);
void stack_clear(stack *s);

//postfix
#define max_item 20
#define postfix_size 200

status is_legal(char *postfix);
status get_item(char *postfix, int *cur_pos, char *item);
void do_calc(stack *s, char op);
element_type calculating(char *postfix);

#endif