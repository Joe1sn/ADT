#include <ADT/graph.h>
#include <stdio.h>
#include <stdlib.h>
#include <ADT/queue.h>
#include <ADT/stack.h>

status mg_init(m_graph *mg, int n, element_type no_edge_value){
    int i, j;
    mg->n = n;
    mg->e = 0;
    mg->a = (element_type **)malloc(n*sizeof(element_type*));
    mg->no_edge = no_edge_value;
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
    if(!lg->a)
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
    e_node *p;
    if(u<0 || v<0 || u>lg->n-1 || v>lg->n-1 || u==v)
        return ERROR;
    p = lg->a[u];
    while(p && p->adjvex!=v)
        p = p->next_arc;
    if(!p)
        return ERROR;
    else
        return OK;
}

status lg_insert(l_graph *lg, int u, int v, element_type w){
    e_node *p;
    if(u<0 || v<0 || u>lg->n-1 || v>lg->n-1 || u==v)
        return ERROR;
    if(lg_exist(lg, u, v))
        return DUPLICATE;
    p = (e_node *)malloc(sizeof(e_node));
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

void lg_dfs(l_graph *lg, int visted[], int v){
    e_node *w;
    printf("%d ",v);
    visted[v] = 1;
    for ( w = lg->a[v]; w; w=w->next_arc)//get marked
        if(!visted[w->adjvex])
            lg_dfs(lg,visted,w->adjvex);
}

void dfs_graph(l_graph *lg){
    int i;
    int *visted =(int *)malloc(sizeof(int)*lg->n);
    for (i = 0; i < lg->n; i++)//init visted array
        visted[i]=0;
    for (i = 0; i < lg->n; i++)
        if(!visted[i])
            lg_dfs(lg, visted, i);
    free(visted);    
}

void lg_bfs(l_graph *lg, int visted[], int v){
    e_node *w;
    queue q;
    q_create(&q,lg->n);
    visted[v]=1;
    printf("%d ",v);
    q_en_queue(&q,v);
    while(q_is_empty(&q))
    {
        q_front(&q,&v);
        q_de_queue(&q);
        for (w = lg->a[v]; w; w=w->next_arc)
        {
            if(!visted[w->adjvex])  //not visted
            {
                visted[w->adjvex] = 1;
                printf("%d ",w->adjvex);
                q_en_queue(&q, w->adjvex);
            }
        }
    }
}

void bfs_graph(l_graph *lg){
    int i;
    int *visted = (int *)malloc(sizeof(int)*lg->n);
    for (i = 0; i < lg->n; i++)
        visted[i] = 0;
    for (i = 0; i < lg->n; i++)
        if(!visted[i])
            lg_bfs(lg,visted,i);
    free(visted);
}

void lg_degree(l_graph *lg, int *in_degree){
    int i;
    e_node *p;
    for (i = 0; i < lg->n; i++)
    in_degree[i] = 0;
    for (i = 0; i < lg->n; i++)
        for(p = lg->a[i]; p; p = p->next_arc)
            in_degree[p->adjvex]++;
}

status lg_top_sort(l_graph *lg, int *topo){
    int i,j,k;
    e_node *p;
    stack s;
    stack_create(&s,lg->n);
    int *in_degree = (int *)malloc(sizeof(int)*lg->n);
    lg_degree(lg, in_degree);
    for(i=0; i<lg->n; i++)
        if(!in_degree[i])
            push(&s,i);
    for(i=0; i<lg->n; i++)
    {
        if(stack_is_empty(&s))
            return ERROR;
        else
        {
            top(&s,&j);
            pop(&s);
            topo[i] = j;
            printf("%d ",j);
            for(p=lg->a[j]; p; p=p->next_arc)   //change the neibor
            {
                k=p->adjvex;
                in_degree[k]--;
                if(!in_degree[k])
                    push(&s,k);
            }
        }
        
    }
    return OK;
}

void event_early(l_graph *lg, int *e_early, int *topo)
{
    int i,k;
    e_node *p;
    for(i=0; i<lg->n; i++)  //init event early array
        e_early[i] = 0;
    for(i=0; i<lg->n; i++)
    {
        k = topo[i];
        for(p = lg->a[k]; p; p=p->next_arc)
        {
            if(e_early[p->adjvex] < e_early[k] + p->w)
                e_early[p->adjvex] = e_early[k] + p->w;
        }
    }
}

void event_late(l_graph *lg, int *e_early, int *topo, int max){
    int i,k;
    e_node *p;
    for(i=0; i<lg->n; i++)  //init event late array
        e_early[i] = max;
    for(i=lg->n-2; i>-1; i--)
    {
        k = topo[i];
        for(p = lg->a[k]; p; p=p->next_arc)
        {
            if(e_early[p->adjvex] > e_early[k] - p->w)
                e_early[p->adjvex] = e_early[k] - p->w;
        }
    }    
}

void active_early(l_graph *lg, int *a_early, int *e_early, int *topo){
    int i,k;
    e_node *p;
    for(i=0; i<lg->n; i++)  //init activity late array
        a_early[i] = 0;
    for(i=0; i<lg->n; i++)
    {
        k = topo[i];
        for (p = lg->a[k]; p; p=p->next_arc)
        {
            if(p->adjvex == k)
                a_early[p->next_arc->adjvex] = e_early[p->adjvex];
        }
        
    }
}

void active_late(l_graph *lg, int *a_late, int *e_late, int *topo, int max){
    int i,k;
    e_node *p;
    for(i=0; i<lg->n; i++)  //init activity late array
        a_late[i] = max;
    for(i=lg->n-2; i>-1; i--)
    {
        k = topo[i];
        for (p = lg->a[k]; p; p=p->next_arc)
        {
            if(p->adjvex == k)
                a_late[p->next_arc->adjvex] = e_late[p->adjvex]-p->w;
        }
        
    }    
}
