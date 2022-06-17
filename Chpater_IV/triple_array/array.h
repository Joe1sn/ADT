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

status create_array(triple_array *tri_a, int m1, int m2, int m3);
status destroy(triple_array *tri_a);
status retrieve_array(triple_array *tri_a, int i1, int i2, int i3, int *x);
status store_array(triple_array *tri_a, int i1, int i2, int i3, int x);
status output(triple_array *tri_a);
status copy_array(triple_array *A,triple_array *B);

#endif