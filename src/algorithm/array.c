#include <stdio.h>
#include <stdlib.h>
#include <ADT/array.h>

status array_create(triple_array *tri_a, int m1, int m2, int m3){
    tri_a->m1 = m1;
    tri_a->m2 = m2;
    tri_a->m3 = m3;
    tri_a->array = (int *)malloc(m1*m2*m3*sizeof(int));
    if(!tri_a->array)
        return ERROR;
    return OK;
}

status array_destroy(triple_array *tri_a){
    if(!tri_a)
        return ERROR;
    if(tri_a->array)
        free(tri_a->array);
    return OK;
}

status array_retrieve(triple_array *tri_a, int i1, int i2, int i3, int *x){
    if(!tri_a->array)
        return ERROR;
    //check the boundary
    if (i1>tri_a->m1 || i2>tri_a->m2 || i3>tri_a->m3||
        i1<0 || i2<0 || i3<0)
        return ERROR;
    // *x = tri_a->array[m1][m2][m3];
    *x = *((tri_a->array)+sizeof(int)*
    (i1*tri_a->m2*tri_a->m3+i2*tri_a->m3+i3));
    return OK;
}

status array_store(triple_array *tri_a, int i1, int i2, int i3, int x){
    if(!tri_a->array)
        return ERROR;
    //check the boundary
    if (i1>=tri_a->m1 || i2>=tri_a->m2 || i3>=tri_a->m3||
        i1<0 || i2<0 || i3<0)
        return ERROR;
    *((tri_a->array)+(i1*tri_a->m2*tri_a->m3+i2*tri_a->m3+i3)) = x;
    return OK;
}

status array_output(triple_array *tri_a){
    int i1,i2,i3;
    if(!tri_a->array)
        return ERROR;
    for (size_t i = 0; i < tri_a->m1; i++)
        for (size_t j = 0; j < tri_a->m2; j++)
            for (size_t k = 0; k < tri_a->m3; k++)
            {
                int value;
                array_retrieve(tri_a,i,j,k,&value);
                printf("array[%d][%d][%d] = %d\n",
                    i,j,k,value);
            }
    return OK;
    
}

status array_copy(triple_array *A,triple_array *B){
    if(!A->array || !B->array)
        return ERROR;
    if(A->array == B->array)
        return ERROR;
    if(A->m1!=B->m1 || A->m2!=B->m2 || A->m3!=B->m3)
        return ERROR;
    for (size_t i = 0; i < A->m1; i++)
        for (size_t j = 0; j < A->m2; j++)
            for (size_t k = 0; k < A->m3; k++)
            {
                // B->array[i][j][k] = A->array[i][j][k];
                int value;
                array_retrieve(A,i,j,k,&value);
                array_store(B,i,j,k,value);
            }
    return OK;
}