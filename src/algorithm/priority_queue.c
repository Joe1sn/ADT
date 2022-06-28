#include <ADT/types.h>
#include <ADT/priority_queue.h>
#include <stdlib.h>
#include <string.h>

/**
 *           heap[p]
 *    heap[2*p+1]   heap[2*p+2]
 */
void adjust_down(element_type heap[], int cur, int boder){
    int p = cur;
    int min_child;
    element_type tmp;

    while(2*p+1 <= boder){
        if ((2*p+2 <= boder) && (heap[2*p+1]>heap[2*p+2]))
            min_child = 2*p+2;
        else
            min_child = 2*p+1;
        if(heap[p]<=heap[min_child])
            break;
        else{
            tmp = heap[p];
            heap[p]=heap[min_child];
            heap[min_child]=tmp;
            /* If it's int type*/
            //heap[p]=heap[min_child]^0x10
            //heap[min_child]=heap[p]^0x10
            p=min_child;
        }
    }
}
void create_heap(element_type heap[], int n){
    int i;
    for(i=(n-2)/2; i>=0; i--)
        adjust_down(heap,i,n-1);
}

/*******prirority
 * This paragraph is for prirority queue
*******/
void prior_q_create(prior_q *pq,int max_size){
    pq->max_size = max_size;
    pq->n = 0;
    pq->q = (element_type *)malloc(max_size*sizeof(element_type));
    memset(pq->q,0,pq->max_size*sizeof(element_type));
}

void prior_q_destroy(prior_q *pq){
    free(pq->q);
    pq->n=0;
    pq->max_size=0;
}

status prior_q_is_empty(prior_q *pq){
    if (pq->n == 0)
        return OK;
    return ERROR;
}

status prior_q_is_full(prior_q *pq){
    if (pq->n == pq->max_size)
        return OK;
    return ERROR;
}

int prior_q_size(prior_q *pq){
    return pq->n;
}

void prior_q_append(prior_q *pq, element_type x){
    if( prior_q_is_full(pq) ) return;
    pq->q[pq->n]=x;
    pq->n++;
    adjust_up(pq->q, pq->n-1);
}

void priro_q_serve(prior_q *pq, element_type *x){
    if(prior_q_is_empty(pq)) return;
    *x = pq->q[0];
    pq->n--;
    pq->q[0]=pq->q[pq->n];
    adjust_down(pq->q, 0, pq->n-1);
}

/**
 *          heap[(p-1)/2]                heap[(p-1)/2]
 *      heap[p]   heap[p+1]   or  heap[p-1]      heap[p]
 */
void adjust_up(element_type heap[], int cur){
    int p =cur;
    element_type tmp;
    while(p>0){
        if(heap[p]<heap[(p-1)/2]){
            tmp = heap[p];
            heap[p]=heap[(p-1)/2];
            heap[(p-1)/2]=tmp;
            /* or t_elemtn_type is int*/
            // heap[(p-1)/2]=heap[p]^0x10
            // heap[p]=heap[(p-1)/2]^0x10
            p=(p-1)/2;
        }
        else
            break;
    }
}