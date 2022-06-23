#include <stdio.h>
#include <stdlib.h>
#include <ADT/stack.h>

status stack_create(stack *s, int max_size){
    s->max_size = max_size;
    s->top = -1; //not a_0, but defore a_0
    s->element = (element_type*)malloc(max_size*sizeof(element_type));
    if(!s->element)
        return ERROR;
    return OK;
}

status stack_destroy(stack *s){
    s->max_size = 0;
    s->top = -1;
    free(s->element);
    s->element = 0;
    return OK;
}

status stack_is_empty(stack *s){
    return s->top == -1;
}

status stack_is_full(stack *s){
    return s->top == s->max_size;
}

status top(stack *s,  element_type *x){
    if(stack_is_empty(s))
        return ERROR;
    *x = s->element[s->top];
    return OK;
}

status push(stack *s, element_type x){
    if (stack_is_full(s))
        return ERROR;
    s->element[++s->top] = x;
    return OK;
}

status pop(stack *s){
    if(stack_is_empty(s))
        return ERROR;
    s->element[s->top] = (element_type)0;
    s->top--;
    return OK;
}

void stack_clear(stack *s){
    s->top=-1;
}