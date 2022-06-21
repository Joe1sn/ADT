#ifndef TREE_H
#define TREE_H
#include <ADT/types.h>

/*******Binart Tree
 * This paragraph is for binary tree 
*******/
typedef struct bt_node
{
    element_type element;
    struct bt_node *l_child;
    struct bt_node *r_child;
    
}bt_node;

typedef struct bin_tree
{
    bt_node *root;
}bin_tree;

void create(bin_tree * bt);
bt_node *new_node(element_type x, bin_tree *l_child, bin_tree *r_child);
BOOL is_empty(bin_tree *bt);
BOOL root(bin_tree *bt, element_type *x);
void make_tree(bin_tree *bt, element_type e, bin_tree *ln, bin_tree *rn);

#endif