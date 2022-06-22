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
bt_node *new_node(element_type x, bt_node *ln, bt_node *rn);
BOOL is_empty(bin_tree *bt);
BOOL root(bin_tree *bt, element_type *x);
void make_tree(bin_tree *bt, element_type e, bin_tree *ln, bin_tree *rn);

void preorder_tree(bin_tree *bt);
void preorder(bt_node *bn);

void inorder_tree(bin_tree *bt);
void inorder(bt_node *bn);

void postorder_tree(bin_tree *bt);
void postorder(bt_node *bn);

void level_order_tree(bin_tree *bt);

#endif