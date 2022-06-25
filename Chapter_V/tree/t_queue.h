#ifndef QUEUE_H
#define QUEUE_H
#include <ADT/types.h>
#include "tree.h"

typedef struct queue
{
    int front;
    int rear;
    int max_size;
    bt_node *element;
}queue;

void create_q(queue *q, int max_size);
void destroy(queue *q);
status is_q_empty(queue *q);
status is_q_full(queue *q);
status front(queue *q, bt_node *x);
status en_queue(queue *q, bt_node *x);
status de_queue(queue *q);
void clear(queue *q);

#endif 