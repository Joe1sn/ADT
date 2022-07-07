#ifndef HASH_H
#define HASH_H

#include <ADT/hash.h>
#include <ADT/types.h>

#define NU -99 //nerver used

typedef struct hash_table
{
    int M;
    int num;
    bool *empty;    //bool marks the table
    int *elements;
}hash_table;

void hash_create(hash_table *ht, int size);
void hash_destroy(hash_table *ht);
void hash_clear(hash_table *ht);
bool hash_is_empty(hash_table *ht);
bool hash_is_full(hash_table *ht);
int hash(int key, int M);
int hash_search(hash_table *ht,int key);
bool hash_insert(hash_table *ht, int key);
bool hash_delete(hash_table *ht, int key);
void hash_output(hash_table *ht);

#endif