# Array & String

# Array

## Array

​	Array is continuous continuous storage data type, usually used in sequencly storage data.Because of each element have the same size,so it can use index to find the data.

​	One-dimensional array is most simple array is c programming.

​	Two-dimensional array always define in `element_type array[x][y]`
![](../imgs/4-array.jpg)

​	Assum $array[4][]4$,so if we kown the $array[0][0]$ address is $63FE80$, element size is $4$, the address of $array[1][2]$ is $63FE80+(1\times4+2)\times 4 = 63FE98$

​	If it's multi-dimensional array like $array[m_1][m_2]...[m_n]$, the location of $array[i_1][i_2]...[i_n]$ could be: $location(arr[0]...[0])+(i_1\times m_2 \times ... \times m_n+i_2\times m_3 \times ... \times m_n+...i_n)\times element\_size$

### ADT

- Data

  the sets of index $<i_1,i_2,...,i_n>$ 
  the sets of value and index, like $<i,v>$

  the length of each dimension is $m_1,m_2,...,m_n$

- Algorithm

  `create_array(A,m_1,m_2,...,m_n)`: allocate n-dimensional array needed space

  `destroy(A)`: destroy n-dimensional array A

  `retrieve_array(A,i_1,i_2,...,i_n)`: check the element existes, if it is, check the bounary and return the value

  `store_array(A,i_1,i_2,...,i_n,x)`: set the element value to x

  `output(A)`: output all element

  `copy_array(A,B)`: if arrayA and arrayB both have the same size, copy element in A to B;

### Triple Array

```c
typedef struct triple_array
{
    int m1;
    int m2;
    int m3;
    int *array;
}triple_array;
```

### create_array

`create_array(A,m_1,m_2,...,m_n)`

allocate n-dimensional array needed space

```c
status create_array(triple_array *tri_a, int m1, int m2, int m3){
    tri_a->m1 = m1;
    tri_a->m2 = m2;
    tri_a->m3 = m3;
    tri_a->array = (int *)malloc(sizeof(int)*m1*m2*m3);
    if(!tri_a->array)
        return ERROR;
    return OK;
}
```

### destroy

`destroy(A)`

destroy n-dimensional array A

```c
status destroy(triple_array *tri_a){
    if(!tri_a)
        return ERROR;
    if(tri_a->array)
        free(tri_a->array);
    return OK;
}
```

### retrieve_array

`retrieve_array(A,i_1,i_2,...,i_n)`

check the element existes, if it is, check the bounary and return the value

here used the equation mentioned before

```c
status retrieve_array(triple_array *tri_a, int i1, int i2, int i3, int *x){
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
```

### store_array

`store_array(A,i_1,i_2,...,i_n,x)`

set the element value to x

```c
status store_array(triple_array *tri_a, int i1, int i2, int i3, int x){
    if(!tri_a->array)
        return ERROR;
    //check the boundary
    if (i1>tri_a->m1 || i2>tri_a->m2 || i3>tri_a->m3||
        i1<0 || i2<0 || i3<0)
        return ERROR;
    // tri_a->array[m1][m2][m3]=x;
    *((tri_a->array)+sizeof(int)*
    (i1*tri_a->m2*tri_a->m3+i2*tri_a->m3+i3)) = x;
    return OK;    
}
```

### output

```c
status output(triple_array *tri_a){
    int i1,i2,i3;
    if(!tri_a->array)
        return ERROR;
    for (size_t i = 0; i < tri_a->m1; i++)
        for (size_t j = 0; j < tri_a->m2; j++)
            for (size_t k = 0; k < tri_a->m3; k++)
            {
                int value;
                retrieve_array(tri_a,i,j,k,&value);
                printf("array[%d][%d][%d] = %d\n",
                    i,j,k,value);
            }
    return OK;
    
}
```

### copy_array

`copy_array(A,B)`

if arrayA and arrayB both have the same size, copy element in A to B;

```c
status copy_array(triple_array *A,triple_array *B){
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
                retrieve_array(A,i,j,k,&value);
                store_array(B,i,j,k,value);
            }
    return OK;
}
```

### main

```c
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
```