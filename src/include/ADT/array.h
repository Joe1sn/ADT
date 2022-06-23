#ifndef ARRAY_H
#define ARRAY_H
#include <ADT/types.h>

typedef struct triple_array
{
    int m1;
    int m2;
    int m3;
    int *array;
}triple_array;

status array_create(triple_array *tri_a, int m1, int m2, int m3);
status array_destroy(triple_array *tri_a);
status array_retrieve(triple_array *tri_a, int i1, int i2, int i3, int *x);
status array_store(triple_array *tri_a, int i1, int i2, int i3, int x);
status array_output(triple_array *tri_a);
status array_copy(triple_array *A,triple_array *B);

#endif