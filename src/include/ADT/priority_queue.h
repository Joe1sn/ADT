#ifndef PRIORITY_QUEUEU
#define PRIORITY_QUEUEU
#include <ADT/types.h>
typedef int element_type;

/*******Heap
 * This paragraph is for heap
*******/
void create_heap(element_type heap[], int n);
void adjust_down(element_type heap[], int cur, int boder);

/*******prior_qrity
 * This paragraph is for prior_qrity queue
*******/
typedef struct prior_q
{
    element_type *q;
    int n;
    int max_size;
}prior_q;

void prior_q_create(prior_q *pq,int max_size);
void prior_q_destroy(prior_q *pq);
status prior_q_is_empty(prior_q *pq);
status prior_q_is_full(prior_q *pq);
int prior_q_size(prior_q *pq);
void prior_q_append(prior_q *pq, element_type x);
void priro_q_serve(prior_q *pq, element_type *x);
void adjust_up(element_type heap[], int cur);

#endif