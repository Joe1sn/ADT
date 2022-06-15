# Stack & Queue

# Stack ADT

​	The stack is like a buket, the first one is deep down the bottom, the last one is on the top.
​	This structure constrain the insert and delete operate only effect on the top of the stack, an it's linear structure.

![](../imgs/3-stack.jpg)

## ADT

- Data
  - 0 or multi data element constitute the linear sequence $(a_0, a_1 , … , a_{n-1})$, they’re one to one relationed
- Algorithm
  - `create(s,max_size)`: Init a Stack **s** with max capacity of **max_size**
  - `destroy(s)`: realse the stack **s** storage space
  - `is_empty(s)`: check the stack is empty
  - `is_full(s)`: check the stack is full
  - `top(s,x)`: get the top element in stack **s**,return it in **x**
  - `push(s,x)`: insert the element **x** to the top of **s**
  - `pop(s)`: pop out the top element in **s**
  - `clear(s)`: wipe out the data in stack **s**, but not delete data

## sequence stack

it's easy to define the data structure

```c
typedef struct stack
{
    int top;
    int max_size;
    element_type *element;
};
```

the **top** is top element in stack, which can be see as $a_i$

### create

`create(s,max_size)`

Init a Stack **s** with max capacity of **max_size**

```c
status create(stack *s, int max_size){
    s->max_size = max_size;
    s->top = -1; //not a_0, but defore a_0
    s->element = (element_type*)malloc(max_size*sizeof(element_type));
    if(!s->element)
        return ERROR;
    return OK;
}
```

### destroy

`destroy(s)`

realse the stack **s** storage space

```c
status destroy(stack *s){
    s->max_size = 0;
    s->top = -1;
    free(s->element);
    s->element = 0;
}
```

### top

`top(s,x)`

get the top element in stack **s**,return it in **x**

```c
status top(stack *s,  element_type *x){
    if(is_empty)
        return ERROR;
    *x = s->element[s->top];
    return OK;
}
```

### push

`push(s,x)`

insert the element **x** to the top of **s**

```c
status push(stack *s, element_type x){
    if (is_full(s))
        return ERROR;
    s->element[s->top++] = x;
    return OK;
}
```

### pop

`pop(s)`

pop out the top element in **s**

```c
status pop(stack *s){
    if(is_empty(s))
        return ERROR;
    s->element[s->top] = (element_type)0;
    s->top--;
    return OK;
}
```

### clear

`clear(s)`

wipe out the data in stack **s**, but not delete data

```c
void clear(stack *s){
    s->top=-1;
}
```

### Test

```c
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(){
    stack *s = (stack *)malloc(sizeof(stack));
    create(s,10);
    for (size_t i = 0; i < 10; i++)
        push(s,i);
    for (size_t i = 0; i < 5; i++)
    {
        printf("**loop No.%d\n",i);
        for (size_t j = 0; j < s->top; j++)
            printf("-------No.%d is %d\n",j,s->element[j]);
        pop(s);
    }
    clear(s);
    printf("elements number: %d\n",s->top);
    destroy(s);
    return 0;
}
```

# Queue ADT

​	The queue must insert at the tail, delete at the head, it's FIFO(First In First Out)
​	The tail is called "rear", The head is called "front"

![](../imgs/3-Queue.jpg)

## ADT

- Data
  - 0 or multi data element constitute the linear sequence $(a_0, a_1 , … , a_{n-1})$, they’re one to one relationed
  - the max length sets to max_size
- Algorithm
  - `create(q,max_size)`: Init a Queue **q** with max capacity of **max_size**
  - `destroy(q)`: realse the stack **q** storage space allocated
  - `is_empty(q)`: check the queue is empty
  - `is_full(q)`: check the queue is full
  - `front(q,x)`: get the head element in queue **q**,return it in **x**
  - `en_queue(q,x)`: insert the element **x** to the end of **q**
  - `de_queue(q)`: delete element in **q**
  - `clear(q)`: wipe out the data in queue **q**, but not delete data

## sequence queue

​	refer to the figuration up here, we can define the struct like

```c
typedef struct queue
{
    int front;
    int rear;
    int max_size;
    element_type *element;
}queue;
```

![](D:\Pictures\typora\3-queue2-1655288561121.jpg)

​	There's a phenomenon called "fake overflow",we need to use the loop queue. if this continued the `rear` pointer will get beyond `front` pointer.At this time we need to `front=(front+1)%max_size`;`rear=(rear+1)%max_size`

​	if `rear == front`, the queue is an empty queue

### create

`create(q,max_size)`

Init a Queue **q** with max capacity of **max_size**

```c
void create(queue *q, int max_size){
    q->max_size = max_size;
    q->element = (element_type *)malloc(max_size*sizeof(element_type));
    q->front = q->rear = 0;
}
```

### destroy

`destroy(q)`

realse the stack **q** storage space allocated

```c
void destroy(queue *q){
    q->max_size=0;
    free(q->element);
    q->front=q->rear=-1;
}
```

### is_empty & is_full

```c
status is_empty(queue *q){
    return q->front == q->rear;
}

status is_full(queue *q){
    return (q->rear+1)%q->max_size==q->front;
}
```

### front

`front(q,x)`

get the head element in queue **q**,return it in **x**

```c
status front(queue *q, element_type *x){
    if(is_empty(q))
        return ERROR;
    *x = q->element[(q->rear)%(q->max_size)];
    return OK;
}
```

### en_queue

`en_queue(q,x)`

insert the element **x** to the end of **q**

```c
status en_queue(queue *q, element_type x){
    if(is_full(q))
        return ERROR;
    q->rear=q->rear%q->max_size+1; //moving rear
    q->element[q->rear] = x;
    return OK;
}
```

### de_queue

`de_queue(q)`

delete element in **q**

```c
status de_queue(queue *q){
    if(is_empty(q))
        return ERROR;
    q->front=(q->front+1)%q->max_size;
    return OK;
}
```

### clear

`clear(q)`

wipe out the data in queue **q**, but not delete data

```c
void clear(queue *q){
    q->front = q->rear = 0;
}
```

### main

test program

```c
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    queue *Q = (queue*)malloc(sizeof(queue));
    create(Q,11);
    for (int i = 0; i < 20; i++)
        en_queue(Q,i+1);
    for (int i = 0; i < 10; i++)
        printf("%d ",Q->element[i]);
    printf("\n");
    for (int i = 10; i > 0; i--)
    {
        printf("**Round : %d\n",10-i);
        for (int j = 0; j <i; j++)
            printf("-------No.%d is %d\n", j, Q->element[j+1]);
        de_queue(Q);
    }
    return 0;
    
}
```

