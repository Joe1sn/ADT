# Graph

> This chapter contains lots of definations and very complex concepts
>
> So this README file is in Chinese(my native laguage), there will be english version few months later

# 基本概念

1. 邻接：简单的说就是两个节点之间有连接
2. 度：入度+出度
   - 入度：指向该节点的连接数
   - 出度：从该节点出发的连接数
3. 路径：顶点序列，如 $(a,b);(b,c);(c,d)$，其中每一个边都在图$G$中
   - 路径长度：路径中边的个数
4. 自回路：允许有边$(a,a)$
5. 多重图：两顶点存在相同的重复的边
6. 连通图
   - 连通：从顶点A到顶点B，可以通过途中路径到达
   - 连通图：任意两个顶点均能连通
   - 连通分量：极大的连通子图的个数
   - 强连通图：顶点A到B和B到A都能够连通
   - 强连通分量：极大的强连通子图的个数
7. 生成树：**无向连通图G**的生成树是一个极小的连通子图，包括图中的所有顶点，和含有能够组成树的$n-1$条边
8. 权：对边进行赋值
9. 网：每条边都存在权

# ADT

## ADT

- data

  顶点的有限、非空集合$G$和边集合$V$，边中元素由偶对顶点表示，如$<u,v>$，$w$表示权值。元素之间的关系十多对多

- algorithm

  `g_init(G,n)`：创建含有$n$个顶点的无边图$G$

  `g_destroy(G)`：撤销一个图$G$

  `g_exist(G,u,v)`：搜索边$<u,v>$是否存在

  `g_insert(G,u,v,w)`：对图$G$中的边$<u,v>$设置权值为$w$的边

  `remove(G,u,v)`：删除边

## 邻接矩阵表示法

假设有图$G$中有$n$个顶点，那么每个点最多就有$n$个边(包括自回路)。那么可以使用一个$n\times n$的矩阵表示，

**对于无向图**：矩阵中的一个元素为$A[u][v]$，通过数值1表示存在$(u,v)$或$(v,u)$

**对于有向图**：矩阵中的一个元素为$A[u][v]$，通过数值1表示存在$<u,v>$

**对于带权无向图**

- $w(u,v)$：$(u,v)$或$(v,u)$成立
- $0$：$u=v$成立
- $-1$：其他

**对于带权有向图**

- $w(u,v)$：$<u,v>$成立
- $0$：$u=v$成立
- $-1$：其他

### 邻接矩阵实现

```c
typedef int element_type;

typedef struct m_graph
{
    element_type a[][];     //matrix
    int n;
    int e;
    element_type no_edge;   //depend on taking the right or not
}m_graph;
```

### 初始化

```c
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
```

### 撤销

```c
void mg_destroy(m_graph *mg){
    int i;
    for (i = 0; i < mg->n; i++)
        free(mg->a[i]);
    free(mg->a);
}
```

### 存在

```c
status mg_exist(m_graph *mg, int u, int v){
    if(u<0 || v<0 || u>mg->n-1 || v>mg->n-1 || u==v || mg->a[u][v] == mg->no_edge)
        return ERROR;
    return OK;
}
```

### 插入

```c
status mg_insert(m_graph *mg, int u, int v, element_type w){
    if(u<0 || v<0 || u>mg->n-1 || v>mg->n-1 || u==v)
        return ERROR;
    if(mg->a[u][v]!=mg->no_edge)
        return DUPLICATE;
    mg->a[u][v] = w;
    mg->e++;
    return OK;
}
```

### 删除

```c
status remove(m_graph *mg, int u, int v){
    if(u<0 || v<0 || u>mg->n-1 || v>mg->n-1 || u==v)
        return ERROR;
    if(mg->a[u][v] == mg->no_edge)
        return NOTPRESENT;
    mg->a[u][v] = mg->no_edge;
    mg->e--;
    return OK;
}
```

基本上就是之前的多维数组管理

## 邻接表表示法

![](../imgs/9-graph1.jpg)

### 邻接表实现

```c
typedef struct e_node
{
    int adjvex;
    element_type w;
    struct e_node *next_arc;    
}e_node;

typedef struct l_graph
{
    int n;
    int e;
    e_node **a;
}l_graph;
```

### 初始化

```c
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
```

### 撤销

```c
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
```

### 搜索

```c
status lg_search(l_graph *lg, int u, int v){
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
```

### 插入

```c
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
```

### 删除

```c
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
```

算法基本上即使在管理多个链表构成的数列

