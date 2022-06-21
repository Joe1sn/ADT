#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    bin_tree a,b,x,y,z;
    create(&a);
    create(&b);
    create(&x);
    create(&y);
    create(&z);

    make_tree(&y,'E',&a,&b);
    make_tree(&y,'F',&a,&b);
    make_tree(&y,'C',&a,&b);
    make_tree(&y,'D',&a,&b);
    make_tree(&y,'B',&a,&b);
}
