#include "seq_list.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("start\n");
    seq_list *list = malloc(sizeof(seq_list));
    init(list, 10);
    for (size_t i = 0; i < 10; i++)
        insert(list,i-1,i+1);
    output(list);

    delete(list,0);
    output(list);

    update(list,5,10);
    output(list);

    destroy(list);
    output(list);    
}