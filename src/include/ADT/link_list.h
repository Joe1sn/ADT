#ifndef LINK_LIST_H
#define LINK_LIST_H
#include <ADT/types.h>

typedef int element_type;

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

status llist_init(sig_link_list *L);
status llist_find(sig_link_list *L, int i, element_type *x);
status llist_insert(sig_link_list *L, int i, element_type x);
status llist_delete(sig_link_list *L, int i);
status llist_output(sig_link_list *L);
void llist_destroy(sig_link_list *L);

#endif