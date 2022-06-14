#ifndef SEQ_LIST_H
#define SEQ_LIST_H
#include <ADT/types.h>

typedef struct seq_list
{
    int n;
    int max_length;
    element_type *elements; //element_type elements[max_length];
} seq_list;

status init(seq_list *L, int m_size);
status destroy(seq_list *L);
status is_empty(seq_list *L);
int length(seq_list *L);
// element_type* find(seq_list *L, int n);
status find(seq_list L, int i, element_type *x);
status insert(seq_list *L, int i, element_type x);
status delete(seq_list *L, int i);
status update(seq_list *L, int i, element_type x);
status output(seq_list *L);


#endif