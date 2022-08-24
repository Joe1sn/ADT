#include <ADT/priority_queue.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    prior_q *pq=malloc(sizeof(prior_q));
    prior_q_create(pq,10);
    int test_case[]={71,74,2,72,54,93,52,28,'\0'};
    int i;
    
    for (i = 0; test_case[i]; i++)
        prior_q_append(pq, test_case[i]);
    while(pq->n>0){
        element_type x;
        priro_q_serve(pq,&x);
        printf("%d ",x);
    }
    return 0;
}