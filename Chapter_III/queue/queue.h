#ifndef QUEUE_H
#define QUEUE_H
#include <ADT/types.h>

typedef struct queue
{
    int front;
    int rear;
    int max_size;
    element_type *element;
}queue;

void create(queue *q, int max_size);
void destroy(queue *q);
status is_empty(queue *q);
status is_full(queue *q);
status front(queue *q, element_type *x);
status en_queue(queue *q, element_type x);
status de_queue(queue *q);
void clear(queue *q);

#endif 