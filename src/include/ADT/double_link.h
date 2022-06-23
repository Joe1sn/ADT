#ifndef DOUBLE_LINK_H
#define DOUBLE_LINK_H
#include<ADT/types.h>

typedef int element_type;
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

status dlink_init(double_link *L);
status dlink_insert(double_link *L, int i, element_type x);
status dlink_delete(double_link *L, int i);

#endif