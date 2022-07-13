#include <stdio.h>
#include <stdlib.h>
#include <ADT/graph.h>

int main()
{
    m_graph *mg = (m_graph *)malloc(sizeof(m_graph));
    mg_init(mg, 6, -1);
    mg_insert(mg,0,1,0);
    mg_insert(mg,1,3,0);
    mg_insert(mg,1,2,0);
    mg_insert(mg,2,0,0);
    mg_insert(mg,3,0,0);
    mg_insert(mg,3,2,0);
    mg_insert(mg,4,0,0);
    mg_insert(mg,4,2,0);
    mg_insert(mg,5,1,0);
    mg_insert(mg,5,3,0);
    int i,j;
    for (i = 0; i < mg->n; i++){
        for (j = 0; j < mg->n; j++)
            printf("%d ",mg->a[i][j]);
        printf("\n");
    }
    mg_destroy(mg);
    free(mg);

    //--------------------------------------
    l_graph *lg = (l_graph *)malloc(sizeof(l_graph));
    lg_init(lg,6);
    lg_insert(lg,0,1,0);
    lg_insert(lg,1,3,0);
    lg_insert(lg,1,2,0);
    lg_insert(lg,2,0,0);
    lg_insert(lg,3,0,0);
    lg_insert(lg,3,2,0);
    lg_insert(lg,4,0,0);
    lg_insert(lg,4,2,0);
    lg_insert(lg,5,1,0);
    lg_insert(lg,5,3,0);
    
    printf("\nDFS>\n");
    dfs_graph(lg);
    printf("\nBFS>\n");
    bfs_graph(lg);
    lg_destroy(lg);
    free(lg);
    return 0;
}