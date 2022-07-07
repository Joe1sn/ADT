#include <ADT/seq_list.h>
#include <ADT/sort.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEST_CASE 50000

bool checkin(seq_list *list){
    int i;
    for (i = 0; i < list->n-1; i++)
    {
        if(list->elements[i]>list->elements[i+1]){
            printf("ERROR in %d,%d",i,i+1);
            return 0;
        }
    }
    return 1;
}

void copy_list(seq_list *l1, seq_list *l2){
    int i;
    for (i = 0; i < l1->n; i++)
        l2->elements[i]=l1->elements[i];
}

int main()
{
    printf("[*]init stastics\n");
    clock_t start,end;

    printf("[*]init slist\n");
    seq_list *list = (seq_list *)malloc(sizeof(seq_list));
    slist_init(list,TEST_CASE);

    seq_list *test = (seq_list *)malloc(sizeof(seq_list));
    slist_init(test,TEST_CASE);

    printf("[*]filling values\n");
    start=clock();
    int i,a;
    srand((unsigned)time(NULL));
    for (i = 0; i < TEST_CASE; i++)
    {
        a = rand()%0x100000;
        slist_insert(list,i-1,a);
        slist_insert(test,i-1,a);
    }
    end=clock();
    printf("time: %.3fs\n", (double)(end - start)/1000);
    //-------------------------using algorithm

    printf("[!]sorting\n");
    printf("  [-]select_sort         ");
    copy_list(list,test);
    start=clock();
    select_sort(test);
    end=clock();
    if(checkin(test)) printf("time: %.3fs\n", (double)(end - start)/1000);
    else printf("sorting ERROR!\n");

    
    printf("  [-]insert_sort         ");
    copy_list(list,test);
    start=clock();
    insert_sort(test);
    end=clock();
    if(checkin(test)) printf("time: %.3fs\n", (double)(end - start)/1000);
    else printf("sorting ERROR!\n");

    printf("  [-]bubble_sort         ");
    copy_list(list,test);
    start=clock();
    bubble_sort(test);
    end=clock();
    if(checkin(test)) printf("time: %.3fs\n", (double)(end - start)/1000);
    else printf("sorting ERROR!\n");


    printf("  [-]quick_sort          ");
    copy_list(list,test);
    start=clock();
    quick_sort(test);
    end=clock();
    if(checkin(test)) printf("time: %.3fs\n", (double)(end - start)/1000);
    else printf("sorting ERROR!\n");  
    
    printf("  [-]merge_sort          ");
    copy_list(list,test);
    start=clock();
    merge_sort(test);
    end=clock();
    if(checkin(test)) printf("time: %.3fs\n", (double)(end - start)/1000);
    else printf("sorting ERROR!\n");


    printf("  [-]heap_srot           ");
    copy_list(list,test);
    start=clock();
    heap_srot(test);
    end=clock();
    if(checkin(test)) printf("time: %.3fs\n", (double)(end - start)/1000);
    else printf("sorting ERROR!\n"); 

    // select_sort(list);
    // insert_sort(list);
    // bubble_sort(list);
    // quick_sort(list);
    // merge_sort(list);
    // heap_srot(list);

    slist_destroy(list);
    slist_destroy(test);
    free(list);
    free(test);

    return 0;
}