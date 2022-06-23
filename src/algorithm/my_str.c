#include <ADT/my_str.h>
#include <ADT/types.h>
#include <stdlib.h>
#include <stdio.h>

status str_create(mystr *s,int len){
    s->len = 0;
    s->max_len = len;
    s->str = (char *)malloc(s->max_len);
    if(!s->str)
        return ERROR;
    for (int i = 0; i < s->len; i++)
        s->str[i] = (char)0;
    return OK;
}

int str_len(mystr *s){
    int len = 0;
    if(!s->str)
        return ERROR;
    for (int i = 0; s->str[i]; i++)
        len++;
    s->len = len;
    return len;
}

status str_clear(mystr *s){
    if(!s->str)
        return ERROR;
    for (int i = 0; i < s->len; i++)
        s->str[i]=(char)0;
    s->len=0;
    return OK;
}

int str_match(mystr *s, mystr *p, int s_start, int p_start, int *s_failed, int *p_failed){
    int i = s_start, j = p_start;
    for (; j < p->len; i++,j++)
    {
        if(s->str[i] != p->str[j])
        {
            *s_failed = i;
            *p_failed = j;
            return ERROR;
        }
    }
    return OK;
}

int str_index(mystr *s, mystr *p, int pos){
    int s_start=pos, p_start=0, s_failed, p_failed;
    for (s_start; s_start <= s->len - p->len ; s_start++)
    {
        if (str_match(s,p,s_start,p_start,&s_failed,&p_failed))
            return s_start;
    }
    return ABNORMAL;
}

void build_nextA(mystr *p, int next[]){
    next[0]=0;
    int prefix=0,i=1;
    while (i<p->len)
    {
        if (p->str[prefix] == p->str[i])
        {
            prefix++;
            next[i++]=prefix;
        }
        else
        {
            if (prefix==0)
            {
                next[i]=0;
                i++;
            }
            else
                prefix = next[prefix - 1];
        }   
    }
}

void build_nextB(mystr *p, int next[]){
    int j = 0, k =-1;
    next[0]=-1;
    while (j < p->len)
    {
        if (k==-1||p->str[j]==p->str[k])
        {
            ++j;++k;
            next[j]=k;
        }
        else
            k=next[k];
    }
}

int KMP_A(mystr *s, mystr *p, int next[]){
    int s_start = 0, p_start = 0;
    while (s_start <= s->len)
    {
        if (s->str[s_start]==p->str[p_start])
        {   ++s_start; ++p_start;   }
        else if (p_start > 0)
            p_start = next[p_start -1];
        else
            ++s_start;

        if (p_start == p->len)
            return s_start - p_start;
        
    }   
}

int KMP_B(mystr *s, mystr *p, int next[]){
    int s_start = 0, p_start = 0, s_failed, p_failed;
    while (s_start <= s->len - p->len)
    {
        if (str_match(s,p,s_start,p_start, &s_failed, &p_failed))
            return s_start - p_start;
        else
        {
            p_start = next[p_failed];
            s_start = s_failed;
            if(p_start == -1)
            {
                p_start = 0;
                s_start++;
            }
        }
        
    }
    return ABNORMAL;
}
