#ifndef GRAPH_H
#define GRAPH_H
#include <ADT/types.h>

typedef int element_type;

typedef struct m_graph
{
    element_type **a;     //matrix
    int n;
    int e;
    element_type no_edge;   //depend on taking the right or not
}m_graph;

status mg_init(m_graph *mg, int n, element_type no_edge_value);
void mg_destroy(m_graph *mg);
status mg_exist(m_graph *mg, int u, int v);
status mg_insert(m_graph *mg, int u, int v, element_type w);
status mg_remove(m_graph *mg, int u, int v);

typedef struct e_node
{
    int adjvex;
    element_type w;
    struct e_node* next_arc;    
}e_node;

typedef struct l_graph
{
    int n;
    int e;
    e_node **a;
}l_graph;

status lg_init(l_graph *lg, int size);
void lg_destroy(l_graph *lg);
status lg_exist(l_graph *lg, int u, int v);
status lg_insert(l_graph *lg, int u, int v, element_type w);
status lg_delete(l_graph *lg, int u, int v);

void lg_dfs(l_graph *lg, int visted[], int v);
void dfs_graph(l_graph *lg);
void lg_bfs(l_graph *lg, int visted[], int v);
void bfs_graph(l_graph *lg);

void lg_degree(l_graph *lg, int *in_degree);
status lg_top_sort(l_graph *lg, int *topo);

void event_early(l_graph *lg, int *e_early, int *topo);
void event_late(l_graph *lg, int *e_early, int *topo, int max);
void active_early(l_graph *lg, int *a_early, int *e_early, int *topo);
void active_late(l_graph *lg, int *a_late, int *e_late, int *topo, int max);

status prim(l_graph *lg, int k, int *close_vex, element_type *low_weight);

#endif