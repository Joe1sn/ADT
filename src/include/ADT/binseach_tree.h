#ifndef BINSEARCH_TREE_H
#define BINSEARCH_TREE_H
#include <ADT/types.h>

typedef int key_type;
typedef int element_type;

typedef struct entry
{
    key_type key;
    element_type data;
}entry;

typedef struct bst_node
{
    entry element;
    struct bst_node *l_child;
    struct bst_node *r_child;
}bst_node, *bst;

bst bst_rec_search(bst t, key_type k);
bst bst_itr_search(bst t, key_type k);
bool bst_insert(bst *t, entry e);
bool dst_delete(bst *t, key_type k);

#endif