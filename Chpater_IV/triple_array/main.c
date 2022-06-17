#include "array.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    triple_array *A = (triple_array*)malloc(sizeof(triple_array));
    triple_array *B = (triple_array*)malloc(sizeof(triple_array));
    create_array(A,2,2,2);
    create_array(B,2,2,2);
    for (int i = 0; i < A->m1; i++)
        for (int j = 0; j < A->m2; j++)
            for (int k = 0; k < A->m3; k++)
            {
                store_array(A,i,j,k,10);
                store_array(B,i,j,k,5);
            }
    printf("--------------Now Output A\n");
    output(A);
    printf("--------------Now Output B\n");
    output(B);

    copy_array(A,B);
    printf("\n");
    printf("\n");
    printf("\n");

    printf("--------------Now Output A\n");
    output(A);
    printf("--------------Now Output B\n");
    output(B);

    destroy(A);
    destroy(B);
    free(A);
    free(B);

    return 0;
}