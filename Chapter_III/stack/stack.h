#ifndef STACK_H
#define STACK_H
#include <ADT/types.h>

typedef struct stack
{
    int top;
    int max_size;
    element_type *element;
}stack;

status create(stack *s, int max_size);
status destroy(stack *s);
status is_empty(stack *s);
status is_full(stack *s);
status top(stack *s,  element_type *x);
status push(stack *s, element_type x);
status pop(stack *s);
void clear(stack *s);

#endif