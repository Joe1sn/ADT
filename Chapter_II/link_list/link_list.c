#include "link_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <ADT/types.h>

status init(sig_link_list *L){
    L->first = NULL;
    L->n=0;
    return OK;
}

status find(sig_link_list *L, int i, element_type *x){
    if (i<-1 || i>L->n-1)
        return ERROR;
    node *temp = L->first;
    for (size_t j = 0; j < i; j++)
        temp = temp->next;
    *x = temp->element;
    return OK;
}

status insert(sig_link_list *L, int i, element_type x){
    node *a_i,*in;
    if (i<-1 || i>L->n-1) //1.check if the i is over boundary
        return ERROR;
    a_i = L->first;
    for (int j = 0; j < i; j++) //2.find a_i
        a_i = a_i -> next;
    in = (node*)malloc(sizeof(node)); //3.init new node
    in->element = x;
    if(i == -1) //new first
    {
        in->next = L->first;
        L->first = in;
    }
    else
    {
        in->next = a_i->next;
        a_i->next = in;
    }
    L->n++;
    return OK;
}

status delete(sig_link_list *L, int i){
    if (i<-1 || i>L->n-1 || !L->n) //1.check if the i is over boundary
        return ERROR;
    node *p = L->first;
    node *q = L->first;
    for (size_t j = 0; j < i-1; j++) //p=a_{i-1}
        p=p->next;
    if (i==0)
        L->first=p->next;   //L->first = a_2
    else
    {
        q=p->next;          //q=a_i
        p->next = q->next;  //a_{i-1} = a_{i+1}
        
    }
    free(q);
    L->n--;
    return OK;
}

status output(sig_link_list *L){
    printf("link list have %d node\n",L->n);
    node *temp = L->first;
    for (size_t i = 0; i < L->n; i++)
    {
        printf("---The No.%d node\n",i);
        printf("   value: %d\n",temp->element);
        printf("   next: %p\n",temp->next);
        temp=temp->next;
    }
}

void destroy(sig_link_list *L){
    node *temp;
    while(L->first->next){
        temp = L->first->next;
        free(L->first);
        L->first = temp;
    }
}

