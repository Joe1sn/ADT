#include <ADT/tree.h>
#include <stdio.h>
#include <stdlib.h>
#include <ADT/t_queue.h>
#include <ADT/t_stack.h>

void create(bin_tree * bt){
    bt->root = NULL;
}

bt_node *new_node(t_element_type x, bt_node *ln, bt_node *rn){
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

BOOL root(bin_tree *bt, t_element_type *x){
    if (bt->root)
    {
        *x = bt->root->element;
        return true;
    }
    return false;
}

void make_tree(bin_tree *bt, t_element_type e, bin_tree *ln, bin_tree *rn){
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

int tree_size(bin_tree *bt){

    return size(bt->root);
}
int size(bt_node *bn){
    if (!bn)
        return 0;
    return size(bn->l_child)+size(bn->r_child)+1;
}

void tree_clear(bin_tree *bt){
    tclear(bt->root);
    bt->root=NULL;
}

void tclear(bt_node *bn){
    if(!bn)
        return;
    tclear(bn->l_child);
    tclear(bn->r_child);
    free(bn);
}

bt_node *pre_create(bt_node *bn){
    char ch;
    ch=getchar();
    if(ch=='#')
        bn=NULL; //create null node
    else
    {
        bn = (bt_node*)malloc(sizeof(bt_node));
        bn->element = ch;
        bn->l_child=pre_create(bn->l_child);
        bn->r_child=pre_create(bn->r_child);
    }
    printf("pre_creating\n");
    return bn;
}
void pre_make(bin_tree *bt){
    bt->root=pre_create(bt->root);
    printf("pre_make\n");
}

bt_node *getfirst(bin_tree *bt,void *s){
    bt_node *p = bt->root;
    if(!p)
        return NULL;
    while(p->l_child != NULL)
    {
        push(s,*p);
        p=p->l_child;
    }
    return p;
}
bt_node *getnext(bt_node *cur, void *s){
    bt_node *p;
    if(cur->r_child != NULL)
    {
        p = cur->r_child;
        while(p->l_child!=NULL)
        {
            push(s,*p);
            p=p->l_child;
        }
        cur=p;
    }
    else if(!stack_is_empty(s))
    {
        top(s, cur);
        pop(s);
    }
    else
    {
        cur=NULL;
        return ERROR;
    }
    return cur;
}

void traverse(bin_tree *bt)
{
    stack s;
    bt_node *cur;
    stack_create(&s,0x100);
    cur = getfirst(bt,&s);
    while(cur)
    {
        printf("%c ",cur->element);
        cur = getnext(cur,&s);
    }
}