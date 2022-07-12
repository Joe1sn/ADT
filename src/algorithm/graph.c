#include <ADT/graph.h>
#include <stdio.h>
#include <stdlib.h>

status mg_init(m_graph *mg, int n, element_type no_edge_value){
    int i, j;
    mg->n = n;
    mg->e = 0;
    mg->a = (element_type **)malloc(n*sizeof(element_type*));
    if (!mg->a)
        return ERROR;
    for(i=0; i<mg->n; i++)
    {
        mg->a[i] = malloc(n*sizeof(element_type));
        for ( j = 0; j < mg->n; j++)
            mg->a[i][j] = mg->no_edge;
        mg->a[i][i] = 0;
    }
    return OK;
}

void mg_destroy(m_graph *mg){
    int i;
    for (i = 0; i < mg->n; i++)
        free(mg->a[i]);
    free(mg->a);
}

status mg_exist(m_graph *mg, int u, int v){
    if(u<0 || v<0 || u>mg->n-1 || v>mg->n-1 || u==v || mg->a[u][v] == mg->no_edge)
        return ERROR;
    return OK;
}

status mg_insert(m_graph *mg, int u, int v, element_type w){
    if(u<0 || v<0 || u>mg->n-1 || v>mg->n-1 || u==v)
        return ERROR;
    if(mg->a[u][v]!=mg->no_edge)
        return DUPLICATE;
    mg->a[u][v] = w;
    mg->e++;
    return OK;
}

status mg_remove(m_graph *mg, int u, int v){
    if(u<0 || v<0 || u>mg->n-1 || v>mg->n-1 || u==v)
        return ERROR;
    if(mg->a[u][v] == mg->no_edge)
        return NOTPRESENT;
    mg->a[u][v] = mg->no_edge;
    mg->e--;
    return OK;
}

status lg_init(l_graph *lg, int size){
    int i;
    lg->n = size;
    lg->e = 0;
    lg->a = (e_node **)malloc(size*sizeof(e_node *));
    if(lg->a)
        return ERROR;
    else
    {
        for (i = 0; i < lg->n; i++)
            lg->a[i] = NULL;
        return OK;
    }
}

void lg_destroy(l_graph *lg){
    int i;
    e_node *p, *q;
    for (i = 0; i < lg->n; i++)
    {
        p = lg->a[i];
        q = p;
        while(p)
        {
            p = p->next_arc;
            free(q);
            q = p;
        }
    }
    free(lg->a);
}

status lg_exist(l_graph *lg, int u, int v){
    if(u<0 || v<0 || u>lg->n-1 || v>lg->n-1 || u==v)
        return ERROR;
    e_node *p = lg->a[u];
    while(p && p->adjvex!=v)
        p = p->next_arc;
    if(!p)
        return ERROR;
    else
        return OK;
}

status lg_insert(l_graph *lg, int u, int v, element_type w){

    if(u<0 || v<0 || u>lg->n-1 || v>lg->n-1 || u==v)
        return ERROR;
    if(lg_exist(lg, u, v))
        return DUPLICATE;
    e_node *p = malloc(sizeof(e_node));
    p->adjvex = v;
    p->w = w;
    p->next_arc = lg->a[u];
    lg->a[u] = p;
    lg->e++;
    return OK;
}

status lg_delete(l_graph *lg, int u, int v){
    e_node *p, *q;
    if(u<0 || v<0 || u>lg->n-1 || v>lg->n-1 || u==v)
        return ERROR;
    p = lg->a[u], q=NULL;
    while(p &&p->adjvex!=v)
    {
        q=p;
        p=p->next_arc;
    }
    if(!p)
        return NOTPRESENT;
    if(q)
        q->next_arc = p->next_arc;
    else    
        lg->a[u] = p->next_arc;
    free(p);
    lg->e--;
    return OK;

}
