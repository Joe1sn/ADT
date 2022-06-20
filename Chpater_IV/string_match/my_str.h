#ifndef MY_STR_H
#define MY_STR_H
#include <ADT/types.h>

typedef struct mystr
{
    char *str;
    int len,max_len;
}mystr;

status create(mystr *s,int len);
int len(mystr *s);
status clear(mystr *s);
int index(mystr *s, mystr *p, int pos);
int match(mystr *s, mystr *p, int s_start, int p_start, int *s_failed, int *p_failed);
void build_nextA(mystr *p, int next[]);
void build_nextB(mystr *p, int next[]);
int KMP_A(mystr *s, mystr *p, int next[]);
int KMP_B(mystr *s, mystr *p, int next[]);
#endif