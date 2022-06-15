#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void create(queue *q, int max_size){
    q->max_size = max_size;
    q->element = (element_type *)malloc(max_size*sizeof(element_type));
    memset(q->element,0,q->max_size*sizeof(element_type));
    q->front = q->rear = 0;
}

void destroy(queue *q){
    q->max_size=0;
    free(q->element);
    q->front=q->rear=-1;
}

status is_empty(queue *q){
    return q->front == q->rear;
}

status is_full(queue *q){
    return (q->rear+1)%q->max_size==q->front;
}

status front(queue *q, element_type *x){
    if(is_empty(q))
        return ERROR;
    *x = q->element[(q->rear)%(q->max_size)];
    return OK;
}

status en_queue(queue *q, element_type x){
    if(is_full(q))
        return ERROR;
    q->rear=q->rear%q->max_size+1; //moving rear
    q->element[q->rear] = x;
    return OK;
}

status de_queue(queue *q){
    if(is_empty(q))
        return ERROR;
    q->front=(q->front+1)%q->max_size;
    return OK;
}

void clear(queue *q){
    q->front = q->rear = 0;
}