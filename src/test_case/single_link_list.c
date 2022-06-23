#include <stdlib.h>
#include <stdio.h>
#include "link_list.h"

int main()
{
    sig_link_list *list = (sig_link_list*)malloc(sizeof(sig_link_list));
    init(list);
    for (int i = 0; i < 10; i++)
        insert(list,i-1,i+1);
    output(list);

    delete(list,4);
    output(list);

    element_type x;
    find(list,3,&x);
    printf("valuse addr %p\n",&x);
    printf("valuse: %d\n",x);

    destroy(list);

    return 0;
}