#ifndef LINK_LIST_H
#define LINK_LIST_H
#include <ADT/types.h>

typedef struct node
{
    element_type element;
    struct node *next;
    
}node;

typedef struct sig_link_list
{
    node *first;
    int n;
}sig_link_list;

status init(sig_link_list *L);
status find(sig_link_list *L, int i, element_type *x);
status insert(sig_link_list *L, int i, element_type x);
status delete(sig_link_list *L, int i);
status output(sig_link_list *L);
void destroy(sig_link_list *L);

#endif