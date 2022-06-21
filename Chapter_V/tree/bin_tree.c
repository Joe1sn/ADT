#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

void create(bin_tree * bt){
    bt->root = NULL;
}

bt_node *new_node(element_type x, bin_tree *ln, bin_tree *rn){
    bt_node *bt_node = (bt_node *)malloc(sizeof(bt_node));
    bt_node->element = x;
    bt_node->l_child = ln;
    bt_node->r_child = rn;
    return bt_node;
}

BOOL is_empty(bin_tree *bt){
    if(bt->root == NULL)
        return true;
    return false;
}

BOOL root(bin_tree *bt, element_type *x){
    if (bt->root)
    {
        *x = bt->root->element;
        return true;
    }
    return false;
}

void make_tree(bin_tree *bt, element_type e, bin_tree *ln, bin_tree *rn){
    if(!bt->root || ln == rn)
        return;
    bt->root = new_node(e, ln->root, rn->root);
    ln->root = rn->root = NULL;
}
