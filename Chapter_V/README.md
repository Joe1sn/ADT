TO DO

- [ ] 非递归遍历代码
- [ ] 线索二叉树概念与图片

# 数和二叉树

> This chapter contains lots of definations and very complex concepts
>
> So this README file is in Chinese(my native laguage), there will be english version few months later

# 树

## 定义

包括$n$个节点的有限集合$D$，$R$是$D$中元素构成的序偶集合

- 每个节点都只有有限个子节点或无子节点；
- 没有父节点的节点称为根节点；
- 每一个非根节点有且只有一个父节点；
- 除了根节点外，每个子节点可以分为多个不相交的子树；
- 树里面没有环路(cycle)

## 术语

1. **节点的度**：一个节点含有的子树的个数称为该节点的度；
2. **树的度**：一棵树中，最大的节点度称为树的度；
3. **叶节点**或**终端节点**：度为零的节点；
4. **非终端节点**或**分支节点**：度不为零的节点；
5. **父亲节点**或**父节点**：若一个节点含有子节点，则这个节点称为其子节点的父节点；
6. **孩子节点**或**子节点**：一个节点含有的子树的根节点称为该节点的子节点；
7. **兄弟节点**：具有相同父节点的节点互称为兄弟节点；
8. 节点的**层次**：从根开始定义起，根为第1层，根的子节点为第2层，以此类推；
9. **深度**：对于任意节点n,n的深度为从根到n的唯一路径长，根的深度为0；
10. **高度**：对于任意节点n,n的高度为从n到一片树叶的最长路径长，所有树叶的高度为0；
11. **堂兄弟节点**：父节点在同一层的节点互为堂兄弟；
12. **节点的祖先**：从根到该节点所经分支上的所有节点；
13. **子孙**：以某节点为根的子树中任一节点都称为该节点的子孙。
14. **森林**：由m（m>=0）棵互不相交的树的集合称为森林；

# 二叉树

就是度小于2的树

## 性质

- 第 $i$ 层最多有 $2^{i-1}$ 个节点

- 高度为 $h$ 的二叉树最多有 $2^h-1$ 个节点

- 包含 $n$ 个节点的二叉树高度至少为 $log_2{n+1}$，最多为 $n$

- 任意一棵二叉树中，叶子节点数目为 $n_0$ ，度为 $2$ 的节点数为 $n_2$ ，则 $n_0=n_2+1$

  证明：

  ​	设二叉树共有 $n$ 个节点，度为1的节点数为 $n_1$ 。
  二叉树中仅仅只有度为$0,1,2$的节点，所以 $n=n_0+n_1+n_2$

  ​	设该二叉树共有 $B$ 条边，除了根节点其他至少有1条边，得到 $B=n-1$ ,$B=n_1+2n_2$
  三式可得: $n_0=n_2+1$

- 如果高度为 $h$ 的二叉树有 $2^h-1$ 个节点称为 **满二叉树**

- 二叉树只有最小面两层叶节点度小于2，最下层节点集中在靠左的若干位置上，这样二叉树就为**完全二叉树**

- 不存在度为1的树叫做 **2-数**

- 具有 $n$ 个节点的完全二叉树的高度为 $[log_2(n+1)]$

  对于完全二叉树的前 $h-1$ 层为满二叉树，有 $2^{h-1}-1$ 个节点
  最下层最多有节点个数不超过 $2^{h-1}$

  - $2^{h-1} \lt n \le 2^{h-1}-1$
  - $h-1 \lt log_2(n+1) \le h$

  所以 $h$ 是不小于 $log_2(n+1)$ 的最小整数

## ADT

- 数据

  节点的有限集合，要么为空，要么为一个根节点个两个子节点，两个子节点也是二叉树

- 算法

  `create(bt)`: 构造一棵空二叉树bt。
  `new_node(x，ln，rn)`: 创建一个新结点，该结点的值为x，ln和rn为该结点的左右孩子结点。
  `IsEmpty(bt)`:若二叉树bt为空，则返回TRUE，否则返回FALSE。
  `tree_clear(bt)`:清除二叉树bt中的所有结点，使之成为空二叉树。
  `root(bt，x)`:若二叉树bt非空，则用x返回其根结点的值，并返回TRUE，否则返回FALSE。
  `make_tree(bt，x，left，right)`:构造一棵二叉树bt，根结点的值为x，以left和right为该根结点的左右子树。`preorder_tree(bt)`: 先序遍历二叉树bt。
  `inorder_tree(bt)`: 中序遍历二叉树bt。
  `postOrder_tree(bt)`: 后序遍历二叉树bt。
  `levelorder_tree(bt)`: 层次遍历二叉树bt。

**节点结构体**

```c
typedef struct bt_node
{
    element_type element;
    struct bt_node *l_child;
    struct bt_node *r_child;
    
}bt_node;
```

**树结构体**

### create

`create(bt)`: 构造一棵空二叉树bt

```c
void create(bin_tree * bt){
    bt->root = NULL;
}
```

### new_node

`new_node(x，ln，rn)`: 创建一个新结点，该结点的值为x，ln和rn为该结点的左右孩子结点。

```c
bt_node *new_node(element_type x, bt_node *ln, bt_node *rn){
    bt_node *p = (bt_node *)malloc(sizeof(bt_node));
    p->element = x;
    p->l_child = ln;
    p->r_child = rn;
    return p;
}
```

### is_empty

`is_empty(bt)`:若二叉树bt为空，则返回TRUE，否则返回FALSE。

```c
BOOL is_empty(bin_tree *bt){
    if(bt->root == NULL)
        return true;
    return false;
}
```

### root

`root(bt，x)`:若二叉树bt非空，则用x返回其根结点的值，并返回TRUE，否则返回FALSE。

```c
BOOL root(bin_tree *bt, element_type *x){
    if (bt->root)
    {
        *x = bt->root->element;
        return true;
    }
    return false;
}
```

### make_tree

`make_tree(bt，x，left，right)`:构造一棵二叉树bt，根结点的值为x，以left和right为该根结的左右子树。

```c
void make_tree(bin_tree *bt, element_type e, bin_tree *ln, bin_tree *rn){
    if(bt->root || ln == rn)
        return;
    bt->root = new_node(e, ln->root, rn->root);
    ln->root = rn->root = NULL;
}
```

# 二叉树遍历

要实现的功能

`preorder_tree(bt)`: 先序遍历二叉树bt。
`inorder_tree(bt)`: 中序遍历二叉树bt。
`postOrder_tree(bt)`: 后序遍历二叉树bt。
`levelorder_tree(bt)`: 层次遍历二叉树bt。

## 递归遍历

既然每个子节点都是一个树，那为什么不用递归去遍历呢？

先不考虑二叉树为空的情况，有以下的递归遍历方法

- **先序遍历(VLR)**

  根节点 -> 先序遍历(左子树) -> 先序遍历(右子树)

- **中序遍历(LVR)**

  中序遍历(左子树) -> 根节点 -> 中序遍历(右子树)

- **后序遍历(LRV)**

  后序遍历(左子树) -> 后序遍历(右子树) -> 根节点

![](../imgs/5-traverse.jpg)

尝试用递归的思想理解

### 先序遍历

`preorder_tree(bt)`: 先序遍历二叉树bt。

```c
void preorder_tree(bin_tree *bt){
    preorde(bt);
}
//VLR
void preorder(bt_node *bn){
    if (!bn)
        return;
    printf("%c",bn->element);
    printf("%c",preorde(bn->l_child));
    printf("%c",preorde(bn->r_child));
}
```

### 中序遍历

`inorder_tree(bt)`: 中序遍历二叉树bt。

```c
//VLR
void preorder_tree(bin_tree *bt){
    preorder(bt->root);
}
void preorder(bt_node *bn){
    if (!bn)
        return;
    printf("%c ",bn->element);
    preorder(bn->l_child);
    preorder(bn->r_child);
}

//LVR
void inorder_tree(bin_tree *bt){
    inorder(bt->root);
}
void inorder(bt_node *bn){
    if (!bn)
        return;
    inorder(bn->l_child);
    printf("%c ",bn->element);
    inorder(bn->r_child);
}
```

### 后序遍历

`postOrder_tree(bt)`: 后序遍历二叉树bt。

```c
//LVR
void inorder_tree(bin_tree *bt){
    inorder(bt->root);
}
void inorder(bt_node *bn){
    if (!bn)
        return;
    inorder(bn->l_child);
    printf("%c ",bn->element);
    inorder(bn->r_child);
}
```

### 小测试

注意：我们还没有写回收函数，只能让程序退出时操作系统回收内存，但是这里仅仅只验证遍历算法是否正确

1. 构建二叉树

   ```c
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
   ```

   虽然这里`bin_tree`都是保存在栈上面的，但是

   `make_tree`调用的`new_node`节点是使用的`malloc`函数分配的，所以节点的链接是不会改变的

   ```c
   bt_node *new_node(element_type x, bt_node *ln, bt_node *rn){
       bt_node *p = (bt_node *)malloc(sizeof(bt_node));
       p->element = x;
       p->l_child = ln;
       p->r_child = rn;
       return p;
   }
   ```

   关于调用过程

   ![](../imgs/5-tree.jpg)

2. 遍历二叉树

   ```c
       printf("preorder: ");
       preorder_tree(&z);
   
       printf("\ninorder: ");
       inorder_tree(&z);
   
       printf("\npostorder: ");
       postorder_tree(&z);
       printf("\n");
   ```

   那么

   - 先序遍历：BDCEF
   - 中序遍历：DBECF
   - 后序遍历：DEFCB

   结果

   ```
   preorder: B D C E F
   inorder: D B E C F
   postorder: D E F C B
   ```

   发现没有问题

### 层次遍历

每次从左到右访问该二叉树的元素，上面的例子使用层次遍历的话就为:`BDCEF`

1. 若二叉树为空，退出；初始化队列Q，根节点入队
2. 队列不为空：
   1. 获取队列头中的节点`p`，将头元素出队
   2. 访问节点`p`中元素
   3. 若左节点存在，左节点进队
   4. 若右节点存在，右节点进队
3. 退出

`levelorder_tree(bt)`: 层次遍历二叉树bt。

```c
void level_order_tree(bin_tree *bt){
    if (!bt->root)
        return;
    queue q;
    create_q(&q,100);
    bt_node *bn;
    en_queue(&q, bt->root);

    while(!is_q_empty(&q))
    {
        
        front(&q,bn);
        de_queue(&q);
        int i;
        printf("%c ",bn->element);
        if(bn->l_child)
            en_queue(&q,bn->l_child);
        if(bn->r_child)
            en_queue(&q,bn->r_child);
    }
    destroy(&q);
}
```

## 遍历的应用

### 计算二叉树节点的个数

使用任意一种方式，存在则总数+1，也可递归使用`size(bin_tree)`函数

```c
int tree_size(bin_tree *bt){
    return size(bt->root);
}
int size(bt_node *bn){
    if (!bn)
        return 0;
    return size(bn->l_child)+size(bn->r_child)+1;
}
```

### 清空二叉树

```c
void tree_clear(bin_tree *bt){
    tclear(bt->root);
    bt->root=NULL;
}

void tclear(bt_node *bn){
    if(!bn)
        return;
    tclear(bn->l_child);
    tclear(bn->r_child);
    free(bn);
}
```

### 先序构建二叉树

之前的二叉树

![](../imgs/5-tree2.jpg)

先序遍历的顺序是：**B D C E F**。那么如何反向构建一颗二叉树？

为了区别叶子节点，叶子结点的两个子节点均为NULL，使用`#`表示，那么上面的顺序就为`BD##CE##F##`
![](../imgs/5-tree3.jpg)

```c
bt_node *pre_create(bt_node *bn){
    char ch;
    ch=getchar();
    if(ch=='#')
        bn=NULL; //create null node
    else
    {
        bn = (bt_node*)malloc(sizeof(bt_node));
        bn->element = ch;
        bn->l_child=pre_create(bn->l_child);
        bn->r_child=pre_create(bn->r_child);
    }
    printf("pre_creating\n");
    return bn;
}
void pre_make(bin_tree *bt){
    bt->root=pre_create(bt->root);
    printf("pre_make\n");
}
```

使用递归同样可以做到交换左右子树、求二叉树高度等

## 非递归遍历

递归其实是一种非常浪费空间的方法，递归深度过高会导致内存耗尽。所以一般希望使用它的迭代版本

二叉树作为一种非线性结构，在进行递归访问的时候我们利用程序的栈来实现对另外一侧节点的访问。如果我们想要线性地、能迭代的访问二叉树就不洗自己实现这种功能，这种保存的信息叫做“线索”，这样就可以定义一颗线索二叉树了。

不过这里不用线索二叉树，大致讲下思路

很明显为了保存这些信息我们需要一个堆栈`s`保存待访问的节点

对该二叉树

![](../imgs/5-tree4.jpg)

- 先序遍历(VLR)

  ```fake_python
  s=stack()
  p=root
  s.push(p)
  while(p!=NULL or !is_empty(s)):
  	print(s.top->value)
  	s.pop()
  	if p->rchild:
  		s.push(p->rchild)
  	elif ->lchild:
  		s.push(p->lchild)
  ```

- 中序遍历(LVR)

  ```fake_python
  s=stack()
  p=root
  s.push(p)
  p=p->left
  while(p!=NULL or !is_empty(s)):
  	while(p):
  		s.push(p) #此处可以让右节点入栈
  		p=p->lchild
  	print(s.top()->value)
  	p=s.top()
  	s.pop()
  	p=p->rchild
  ```

  回溯的时候右节点入栈

- 后序遍历(LRV)

  ```fake_python
  s=stack()
  p=root
  while(p!=NULL or !is_empty(s)):
  	while(p):
  		s.push(p)
  		if(p->lchild): p = p->lchild
  		elif(p->rchild): p = p->rchild
  	print(s.top())
  	p = s.top()
      s.pop()
  	if s and s.top()->lchild == p:
  		p = p->rchild
  	else:
  		p = NULL  
  ```

  若为左节点，则右节点入栈

  若为右节点，返回上一层

## 线索二叉树

### 构建

叶子结点的指针空余带来的是很多没有被利用的空间

![](../imgs/5-tree5.jpg)

- **Ltag**
  - **0**: `lchild`指向左节点
  - **1**: `lchild`指向该节点的遍历前驱

- **Rtag**
  - **0**: `rchild`指向左节点
  - **1**: `rchild`指向该节点的遍历后继

最后就可以按照遍历方式得到一个链表，依次访问该链表就是该遍历方式的遍历顺序

![](D:\Pictures\typora\5-tree4.jpg)

上图的中序遍历就是：CBDAEGF

对应的中序穿线树为

![](../imgs/5-tree7.jpg)

### 遍历（中序）

使用python伪代码

```fake_python
//中序遍历
p=root
while p->lchild:
	p = p->lchild
while p:
	print(p)
	if(p->rtag==0 and p->rchild): #不是线索
		p = p->rchild
        while(p->lchild):
            p = p->lchild
	else: p = p->rchild
```

跟着步骤得到遍历顺序: CBDAEGF
这里只得到了中序遍历的结果

# 树和森林

# 堆和优先权队列

# 哈夫曼树和哈夫曼编码
