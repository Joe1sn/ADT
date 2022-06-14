#ifndef DOUBLE_LINK_H
#define DOUBLE_LINK_H
#include<ADT/types.h>

typedef struct node
{
    element_type n;
    struct node* front;
    struct node* back;    
}node;

typedef struct double_link
{
    node *head;
    int n;
}double_link;

status init(double_link *L);
status insert(double_link *L, int i, element_type x);
status delete(double_link *L);

#endif