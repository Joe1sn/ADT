#include <ADT/seq_list.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("start\n");
    seq_list *list = malloc(sizeof(seq_list));
    slist_init(list, 10);
    for (size_t i = 0; i < 10; i++)
        slist_insert(list,i-1,i+1);
    slist_output(list);

    slist_delete(list,0);
    slist_output(list);

    slist_update(list,5,10);
    slist_output(list);

    slist_destroy(list);
    slist_output(list);    
}