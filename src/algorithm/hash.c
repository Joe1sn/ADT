#include <ADT/hash.h>
#include <ADT/types.h>
#include <stdio.h>
#include <stdlib.h>

void hash_create(hash_table *ht, int size){
    int i;
    ht->M=size;
    ht->num=0;
    ht->empty=(BOOL *)malloc(sizeof(BOOL)*size);
    ht->elements=(int *)malloc(sizeof(int)*size);
    for (i = 0; i < size; i++)
    {
        ht->empty[i]=true;
        ht->elements[i]=NU;
    }
}

void hash_destroy(hash_table *ht){
    free(ht->elements);
    free(ht->empty);
}

void hash_clear(hash_table *ht){
    int i;
    ht->num=0;
    for (i = 0; i < ht->M; i++)
    {
        ht->empty[i]=true;
        ht->elements[i]=NU;
    }
}

BOOL hash_is_empty(hash_table *ht){
    if(ht->num == 0)
        return true;
    else
        return false;
}

BOOL hash_is_full(hash_table *ht){
    if(ht->num == ht->M)
        return true;
    else
        return false;
}

int hash(int key, int M){
    return key%M;
}

int hash_search(hash_table *ht,int key){
    int anchor, pos;
    anchor=pos=hash(key,ht->M);
    do{
        if(ht->empty[pos])              //reached empty space
            return NOTPRESENT;
        if(ht->elements[pos]==key)
            return pos;
        pos=(pos+1)%ht->M;
    }while(pos!=anchor);
    return NOTPRESENT;
}

BOOL hash_insert(hash_table *ht, int key){
    int anchor,i;
    if(hash_is_full(ht))
        return false;
    if(hash_search(ht,key)!=NOTPRESENT) //key is already in hash table
        return false;
    i=anchor=hash(key,ht->M);
    do{
        if(ht->elements[i]==NU) //current position can be used
        {
            ht->elements[i]=key;
            ht->empty[i]=false;
            ht->num++;
            return true;
        }
        i=(i+1)%ht->M;
    }while (i != anchor);
    return false;
}

BOOL hash_delete(hash_table *ht, int key){
    if(hash_is_empty(ht))
        return false;
    int pos = hash_search(ht,key);
    if (pos==NOTPRESENT)
        return false;
    else{
        ht->elements[pos]=NU;
        ht->num--;
        return true;
    }
}

void hash_output(hash_table *ht){
    int i;
    for (i = 0; i < ht->M; i++)
        printf("%5d ",ht->elements[i]);
    printf("\n");
    for (i = 0; i < ht->M; i++)
        printf("%5d ",ht->empty[i]);
    printf("\n");
}
