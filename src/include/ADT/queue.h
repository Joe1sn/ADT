#ifndef QUEUE_H
#define QUEUE_H
#include <ADT/types.h>

typedef int element_type;

typedef struct queue
{
    int front;
    int rear;
    int max_size;
    element_type *element;
}queue;

void q_create(queue *q, int max_size);
void q_destroy(queue *q);
status q_is_empty(queue *q);
status q_is_full(queue *q);
status q_front(queue *q, element_type *x);
status q_en_queue(queue *q, element_type x);
status q_de_queue(queue *q);
void q_clear(queue *q);

#endif 