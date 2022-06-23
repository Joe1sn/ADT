#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ADT/queue.h>

void q_create(queue *q, int max_size){
    q->max_size = max_size;
    q->element = (element_type *)malloc(max_size*sizeof(element_type));
    memset(q->element,0,q->max_size*sizeof(element_type));
    q->front = q->rear = 0;
}

void q_destroy(queue *q){
    q->max_size=0;
    free(q->element);
    q->front=q->rear=-1;
}

status q_is_empty(queue *q){
    return q->front == q->rear;
}

status q_is_full(queue *q){
    return (q->rear+1)%q->max_size==q->front;
}

status q_front(queue *q, element_type *x){
    if(q_is_empty(q))
        return ERROR;
    *x = q->element[(q->front+1)%(q->max_size)];
    return OK;
}

status q_en_queue(queue *q, element_type x){
    if(q_is_full(q))
        return ERROR;
    q->rear=(q->rear+1)%q->max_size; //moving rear
    q->element[q->rear] = x;
    return OK;
}

status q_de_queue(queue *q){
    if(q_is_empty(q))
        return ERROR;
    q->front=(q->front+1)%q->max_size;
    return OK;
}

void q_clear(queue *q){
    q->front = q->rear = 0;
}