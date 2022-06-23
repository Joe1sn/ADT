#include <stdlib.h>
#include <ADT/double_link.h>

status dlink_init(double_link *L){
    L->head = (node*)malloc(sizeof(node));
    L->n=0;
    if(!L->head)
        return ERROR;
    L->head->front=0;
    L->head->back=0;
    return OK;
}

status dlink_insert(double_link *L, int i, element_type x){
    node *p = L->head;
    node *q = (node*)malloc(sizeof(node));
    q->n = x;
    for (int j = 0; j < i; j++)
        p = p->back;
    q->front=p;
    q->back=p->back; 
    q->back->front = q;
    p->back = q;
    L->n++;
    return OK;
}

status dlink_delete(double_link *L, int i){
    node *p = L->head;
    for (int j = 0; j < i; j++)
        p=p->back;
    p->front->back = p->back;
    p->back->front = p->front;
    free(p);
}
