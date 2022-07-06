#include <ADT/seq_list.h>
#include <ADT/sort.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEST_CASE 0x200

int main()
{
    printf("--------------init slist\n");
    seq_list *list = (seq_list *)malloc(sizeof(seq_list));
    slist_init(list,TEST_CASE);
    printf("--------------filling values\n");

    int i,a;
    srand((unsigned)time(NULL));
    for (i = 0; i < TEST_CASE; i++)
    {
        a = rand()%0x100;
        slist_insert(list,i-1,a);
    }
    // slist_output(list);

    
    //-------------------------using algorithm
    printf("--------------sorting\n");
    // select_sort(list);
    // insert_sort(list);
    // bubble_sort(list);
    quick_sort(list);

    // slist_output(list);

    

    printf("--------------checking\n");
    for (i = 0; i < list->n-1; i++)
    {
        if(list->elements[i]>list->elements[i+1]){
            printf("ERROR in %d,%d",i,i+1);
            return 0;
        }
    }
    printf("--------------Alright!\n");
    return 0;
}