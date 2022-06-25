#include <ADT/t_queue.h>
#include <ADT/tree.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void create_q(queue *q, int max_size){
    q->max_size = max_size;
    q->element = (bt_node *)malloc(max_size*sizeof(bt_node));
    memset(q->element,0,q->max_size*sizeof(bt_node));
    q->front = q->rear = 0;
}

void destroy(queue *q){
    q->max_size=0;
    free(q->element);
    q->front=q->rear=-1;
}

status is_q_empty(queue *q){
    return q->front == q->rear;
}

status is_q_full(queue *q){
    return (q->rear+1)%q->max_size==q->front;
}

status front(queue *q, bt_node *x){
    if(is_q_empty(q))
        return ERROR;
    *x = q->element[(q->front+1)%(q->max_size)];
    return OK;
}

status en_queue(queue *q, bt_node *x){
    if(is_q_full(q))
        return ERROR;
    q->rear=(q->rear+1)%q->max_size; //moving rear
    q->element[q->rear] = *x;
    return OK;
}

status de_queue(queue *q){
    if(is_q_empty(q))
        return ERROR;
    q->front=(q->front+1)%q->max_size;
    return OK;
}

void clear(queue *q){
    q->front = q->rear = 0;
}