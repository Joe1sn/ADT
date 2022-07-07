#include <ADT/types.h>
#include <ADT/binseach_tree.h>
#include <stdio.h>
#include <stdlib.h>

bst bst_rec_search(bst t, key_type k){
    if(!t)
        return ERROR;
    else if(t->element.key == k)
        return t;
    else if(t->element.key > k)
        return bst_rec_search(t->l_child);
    else
        return bst_rec_search(t->r_child);
}

bst bst_itr_search(bst t, key_type k){
    while(t)
    {
        if(t->element.key > k)
            t = t->l_child;
        else if(t->element.key < k)
            t = t->r_child;
        else
            return t;
    }
    return ERROR;
}

bool bst_insert(bst *t, entry e){
    bst_node *p=t, *q, *r;
    key_type = e.key;
    while(p)    //check the same,and set `q` to the proper position
    {
        q = p;
        if(p->element.key > k)
            p=p->l_child;
        else if(p->element.key < k)
            p=p->r_child;
        else{
            printf("Duplicate\n");
            return ERROR;
        }
    }
    r = (bst)malloc(sizeof(bst_node)); //create node
    r->element = e; r->l_child=NULL; r->r_child=NULL;
    //start insert
    if(!t)
        t=r;                        //root node
    else if(t->element.key > k)
        q->l_child = r;
    else if(t->element.key < k)
        q->r_child = r;
    return true;
}

bool dst_delete(bst *t, key_type k)
{
    bst_node *c, *r, *s, *p = t, *q;
    //1.check if the node exists
    while(p && p->element.key != k)
    {
        q = p; //set `q` to the proper position
        if(p->element.key > k)
            p = p->l_child;
        else
            p = p->r_child;
    }
    if(!p)
    {
        printf("Duplicated!\n");
        return ERROR;
    }
    //2.if p have both child
    if(p->l_child && p->r_child)
    {
        s=p->r_child;
        r=p;
        //find p's LVR back node `s`
        while(s->l_child)
        {
            r=s;
            s=s->l_child;
        }
        //[!]-- copy `s` to `p` --[!]
        p->element = s->element;
        p = s; q = r;
    }   //now `q` is parent of `p`
    //3. let `c` to replace `p`
    if(p->l_child)
        c = p->l_child;
    else
        c = p->r_child;
    //4. replacement
    if(p==t)                //if delete root
        t=c;
    else if(p==q->l_child)  //`c` replace `p`
        q->l_child = c;
    else if(p==q->r_child)
        q->r_child = c;
    free(p);
    return true;   
}