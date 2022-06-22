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

//---------traverse binary tree
//-VLR
void preorder_tree(bin_tree *bt);
void preorder(bt_node *bn);
//-LVR
void inorder_tree(bin_tree *bt);
void inorder(bt_node *bn);
//-LRV
void postorder_tree(bin_tree *bt);
void postorder(bt_node *bn);
//-layer traverse
void level_order_tree(bin_tree *bt);

int tree_size(bin_tree *bt);
int size(bt_node *bn);

void tree_clear(bin_tree *bt);
void tclear(bt_node *bn);
//build from VLR
bt_node *pre_create(bt_node *t);
void pre_make(bin_tree *bt);

bt_node *getfirst(bin_tree *bt, stack *s);
bt_node *next(bin_tree *bt, stack *s);
void traverse(bin_tree *bt);


#endif