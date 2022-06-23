#ifndef SEQ_LIST_H
#define SEQ_LIST_H
#include <ADT/types.h>

typedef int element_type;

typedef struct seq_list
{
    int n;
    int max_length;
    element_type *elements; //element_type elements[max_length];
} seq_list;

status slist_init(seq_list *L, int m_size);
status slist_destroy(seq_list *L);
status slist_is_empty(seq_list *L);
int slist_length(seq_list *L);
// element_type* find(seq_list *L, int n);
status slist_find(seq_list L, int i, element_type *x);
status slist_insert(seq_list *L, int i, element_type x);
status slist_delete(seq_list *L, int i);
status slist_update(seq_list *L, int i, element_type x);
status slist_output(seq_list *L);


#endif