#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void create(bin_tree * bt){
    bt->root = NULL;
}

bt_node *new_node(element_type x, bt_node *ln, bt_node *rn){
    bt_node *p = (bt_node *)malloc(sizeof(bt_node));
    p->element = x;
    p->l_child = ln;
    p->r_child = rn;
    return p;
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
    if(bt->root || ln == rn)
        return;
    bt->root = new_node(e, ln->root, rn->root);
    ln->root = rn->root = NULL;
}

//VLR
void preorder_tree(bin_tree *bt){
    preorder(bt->root);
}
void preorder(bt_node *bn){
    if (!bn)
        return;
    printf("%c ",bn->element);
    preorder(bn->l_child);
    preorder(bn->r_child);
}

//LVR
void inorder_tree(bin_tree *bt){
    inorder(bt->root);
}
void inorder(bt_node *bn){
    if (!bn)
        return;
    inorder(bn->l_child);
    printf("%c ",bn->element);
    inorder(bn->r_child);
}

//LRV
void postorder_tree(bin_tree *bt){
    postorder(bt->root);
}
void postorder(bt_node *bn){
    if (!bn)
        return;
    postorder(bn->l_child);
    postorder(bn->r_child);
    printf("%c ",bn->element);
    
}

void level_order_tree(bin_tree *bt){
    if (!bt->root)
        return;
    queue q;
    create_q(&q,100);
    bt_node *bn;
    en_queue(&q, bt->root);

    while(!is_q_empty(&q))
    {
        
        front(&q,bn);
        de_queue(&q);
        int i;
        printf("%c ",bn->element);
        if(bn->l_child)
            en_queue(&q,bn->l_child);
        if(bn->r_child)
            en_queue(&q,bn->r_child);
    }
    destroy(&q);
}
