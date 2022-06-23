#include <ADT/array.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    triple_array *A = (triple_array*)malloc(sizeof(triple_array));
    triple_array *B = (triple_array*)malloc(sizeof(triple_array));
    array_create(A,2,2,2);
    array_create(B,2,2,2);
    for (int i = 0; i < A->m1; i++)
        for (int j = 0; j < A->m2; j++)
            for (int k = 0; k < A->m3; k++)
            {
                array_store(A,i,j,k,i+j+k+10);
                array_store(B,i,j,k,5);
            }
    printf("--------------Now Output A\n");
    array_output(A);
    printf("--------------Now Output B\n");
    array_output(B);

    array_copy(A,B);
    printf("\n");
    printf("\n");
    printf("\n");

    printf("--------------Now Output A\n");
    array_output(A);
    printf("--------------Now Output B\n");
    array_output(B);

    array_destroy(A);
    array_destroy(B);
    free(A);
    free(B);

    return 0;
}