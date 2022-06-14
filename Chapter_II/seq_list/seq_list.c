#include "seq_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <ADT/types.h>

status init(seq_list *L, int m_size){
    L->max_length = m_size;
    L->n = 0;
    L->elements = (element_type *)malloc(sizeof(element_type)*m_size);
    if(L->elements) return OK;
    else return ERROR;
}

status destroy(seq_list *L){
    if (L){
        L->n=0;
        L->max_length=0;
        free(L->elements);
        if (!L) return OK;
    }
    return ERROR;
}

status is_empty(seq_list *L){
    if (L->n == 0) return OK;
    else return ERROR;
}

int length(seq_list *L){
    if (L) return L->n;
    else return (int)ERROR;
}

// element_type* find(seq_list *L, int n){
//     if (L && n >=0 && L->n >=n)
//         return &(L->elements[n*sizeof(element_type)]);
//     else return ERROR;
// }

status find(seq_list L, int i, element_type *x){
    if(i<0 || i>L.n-1)
        return ERROR;
    *x = L.elements[i];
    return OK;
}

status insert(seq_list *L, int i, element_type x){
    int j=0;
    if (i< -1 || i> L->n-1)     //1.check if the i is over boundary
        return ERROR;
    if (L->n == L->max_length)  //2.check if the list is full
        return ERROR;
    for (j=L->n-1; j >= i; j--) //3.let the value move back
        L->elements[j+1]=L->elements[j];
    L->elements[i+1] = x; //4.set the value
    L->n++;
    return OK;
}

status delete(seq_list *L, int i){
    int j=0;
    if (i<-1 || i > L->n-1) //1.check if the i is over boundary
        return ERROR;
    // if (!L->n)              //2.check if the L is empty
    if (is_empty(L))
        return ERROR;
    for(j=i+1; j < L->n; j++)
        L->elements[j-1] = L->elements[j];
    L->n--;
    return OK;
}

status update(seq_list *L, int i, element_type x){
    if (!L || i<-1 || i> L->n)
        return ERROR;
    if (L->elements[i]){
        L->elements[i] = x;
        return OK;
    }
    return ERROR;
}

status output(seq_list *L){
    if (!L) return ERROR;
    printf("seq_list have %d elements\n",L->n);
    printf("seq_list max length %d\n",L->max_length);
    printf("values \n");
    for (size_t i = 0; i < L->n; i++)
        printf("%d ",L->elements[i]);
    printf("\n");
    return OK;
}