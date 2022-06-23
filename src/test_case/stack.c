#include <stdio.h>
#include <stdlib.h>
#include <ADT/stack.h>

int main(){
    stack *s = (stack *)malloc(sizeof(stack));
    stack_create(s,10);
    for (size_t i = 0; i < 10; i++)
        push(s,i);
    for (size_t i = 0; i < 5; i++)
    {
        printf("**loop No.%d\n",i);
        for (size_t j = 0; j < s->top; j++)
            printf("-------No.%d is %d\n",j,s->element[j]);
        pop(s);
    }
    stack_clear(s);
    printf("elements number: %d\n",s->top);
    stack_destroy(s);
    return 0;
}