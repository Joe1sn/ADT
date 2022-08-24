#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ADT/my_str.h>

int main(){
    char *main = "ABABABCAA";
    char *sub = "ABABC";

    mystr *s = (mystr *)malloc(sizeof(mystr));
    mystr *p = (mystr *)malloc(sizeof(mystr));
    str_create(s,strlen(main)+0x10);
    str_create(p,strlen(sub)+0x10);
    
    strcpy(s->str,main);
    s->len=(strlen(s->str));
    strcpy(p->str,sub);
    p->len=(strlen(p->str));


    printf("mystr S is: %s\n",s->str);
    printf("mystr P is: %s\n",p->str);

    int next[p->len];
    build_nextA(p,next);
    printf("KMP_A: %d\n",KMP_A(s,p,next));
    build_nextB(p,next);
    printf("KMP_B: %d\n",KMP_B(s,p,next));
    printf("index: %d\n",str_index(s,p,0));
    return 0;
}