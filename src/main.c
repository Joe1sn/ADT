#include <ADT/hash.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    hash_table *ht = (hash_table*)malloc(sizeof(hash_table));
    hash_create(ht,0x10);

    printf("--------------hash insert\n");
    int i,a;
    srand((unsigned)time(NULL));
    for (i = 0; i < 0x15; i++)
    {
        a = rand()%0x100;
        hash_insert(ht,a);
    }
    hash_output(ht);

    printf("--------------hash delete\n");
    int del_list[5];
    for (i = 0; i < 5; i++)
        del_list[i]=ht->elements[5+i];
    for (i = 0; i < 5; i++)
        hash_delete(ht,del_list[i]);
    hash_output(ht);

    printf("--------------hash insert again\n");
    for (i = 5; i < 10; i++)
    {
        a = rand()%0x100;
        hash_insert(ht,a);
    }
    hash_output(ht);

    return 0;
}