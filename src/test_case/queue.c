#include <stdlib.h>
#include <stdio.h>
#include <ADT/queue.h>

int main()
{
    queue *Q = (queue*)malloc(sizeof(queue));
    q_create(Q,11);
    for (int i = 0; i < 20; i++)
        q_en_queue(Q,i+1);
    for (int i = 0; i < 10; i++)
        printf("%d ",Q->element[i]);
    printf("\n");
    for (int i = 10; i > 0; i--)
    {
        printf("**Round : %d\n",10-i);
        for (int j = 0; j <i; j++)
            printf("-------No.%d is %d\n", j, Q->element[j+1]);
        q_de_queue(Q);
    }
    return 0;
    
}