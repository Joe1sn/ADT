#ifndef GRAPH_H
#define GRAPH_H
#include <ADT/types.h>

typedef int element_type;

typedef struct m_graph
{
    element_type a[][];     //matrix
    int n;
    int e;
    element_type no_edge;   //depend on taking the right or not
}m_graph;

status mg_init(m_graph *mg, int n, element_type no_edge_value);
void mg_destroy(m_graph *mg);
status mg_exist(m_graph *mg);
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

#endif