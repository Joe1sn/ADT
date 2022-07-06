#include <ADT/sort.h>
#include <ADT/seq_list.h>
#include <stdio.h>
#include <stdlib.h>

#define swap(a,b) (a^=b,b^=a,a^=b)

int find_min(seq_list *list, int start_idx){
    int i,min_idx = start_idx;
    for (i = start_idx+1; i < list->n; i++){
        if(list->elements[i]<list->elements[min_idx])
            min_idx = i;
    }
    return min_idx;
}

void select_sort(seq_list *list){
    int min_idx, start = 0;
    while (start < list->n-1)
    {
        min_idx = find_min(list,start);
        if (min_idx != start){
            //some binary magic to swap element
            swap(list->elements[start],list->elements[min_idx]);
        }
        start++;
    }    
}

void insert_sort(seq_list *list){
    int i, j, temp;
    for (i = 1; i < list->n; i++)
    {
        temp = list->elements[i];
        for (j = i-1; j >=0; j--)
        {
            if(temp < list->elements[j])
                list->elements[j+1]=list->elements[j];
            else
                break;
        }
        list->elements[j+1] = temp;
    }
}

void bubble_sort(seq_list *list){
    int i,j;
    BOOL flag=false;
    while(flag!=true){
        flag=true;
        for (i = 0; i < list->n-1; i++)
        {
            if(list->elements[i] > list->elements[i+1]){
                swap(list->elements[i],list->elements[i+1]);
                flag=false;
            }
        }
    }
}

int partition(seq_list *list, int low, int high){
    int i = low, j = high + 1;
    int k = list->elements[low];
    while(i < j){
        while(list->elements[--j] > k);
        while(i < j && list->elements[++i] < k);
        if(i < j)
            swap(list->elements[i],list->elements[j]);
    }
    if(low != j)
    swap(list->elements[low],list->elements[j]);
    return j;
}

void q_sort(seq_list *list, int low, int high){
    int k;
    if(low < high){
        k = partition(list, low, high);
        q_sort(list, low, k-1);
        q_sort(list, k+1, high);
    }
}

void quick_sort(seq_list *list){
    q_sort(list, 0, list->n-1);
}
