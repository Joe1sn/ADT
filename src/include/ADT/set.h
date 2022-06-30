#ifndef SET_H
#define SET_H

typedef int element_type;

typedef struct listset
{
    int n;
    int max_len;
    element_type *element;
}listset;


#endif