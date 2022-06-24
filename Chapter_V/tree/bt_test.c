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
    make_tree(&z,'F',&a,&b);
    make_tree(&x,'C',&y,&z);
    make_tree(&y,'D',&a,&b);
    make_tree(&z,'B',&y,&x);

    // printf("preorder: ");
    // preorder_tree(&z);

    // printf("\ninorder: ");
    // inorder_tree(&z);

    // printf("\npostorder: ");
    // postorder_tree(&z);

    // printf("\nlevel order tree: ");
    // level_order_tree(&z);

    
    // printf("\ntree size: %d",tree_size(&z));
    // printf("\nnow is clear tree");
    // tree_clear(&z);
    // printf("\ntree size: %d\n",tree_size(&z));

    // pre_make(&z);
    // printf("\ntree size: %d\n",tree_size(&z));

    traverse(&z);

    return 0;
}