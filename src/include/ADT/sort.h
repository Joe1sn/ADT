#ifndef SORT_H
#define SORT_H
#include <ADT/types.h>
#include <ADT/seq_list.h>

int find_min(seq_list *list, int start_idx);
void select_sort(seq_list *list);
void insert_sort(seq_list *list);
void bubble_sort(seq_list *list);
void heap_srot(seq_list *list);

//quick sort
int partition(seq_list *list, int low, int high);
void q_sort(seq_list *list, int low, int high);
void quick_sort(seq_list *list);

//merge sort
void merge(seq_list *list, element_type *temp, int low, int n1, int n2);
void merge_sort(seq_list *list);


#endif