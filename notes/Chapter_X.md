# Inside Sort

ok, one of the most fancy part about algorithm

1. stable

   origin sequence: `(a,90),(B,80),(c,90)`, sorted by number.

   stable sort: `(b,80),(a,90),(c,90)`, the relative position is not changed in `(a,90)` and `(c,90)`

   unstable sort: `(b,80),(c,90),(a,90)`, the relative position is has changed in `(a,90)` and `(c,90)`

2. sorted pass

   just convient our time complexity analyze

3. time complexity & space complexity

recommend chinese post: https://www.zhihu.com/question/23148377/answer/718815659

## simple selection sort

each loop select the smallest element in list and swap

```c
#define swap(a,b) (a^=b,b^=a,a^=b)

int find_min(seq_list *list, int start_idx){
    int i,min_idx = start_idx;
    for (i = start_idx+1; i < list->n; i++){
        if(list->elements[i]<list->elements[min_idx])
            min_idx = i;
    }
    return min_idx;
}

void select_sort(seq_list *list){
    int min_idx, start = 0;
    while (start < list->n-1)
    {
        min_idx = find_min(list,start);
        if (min_idx != start){
            //some binary magic to swap element
            swap(list->elements[start],list->elements[min_idx]);
        }
        start++;
    }    
}
```

attention: if start equals min_idx, their were point to same memory and that will failed our xor magic, so here need to check.

- stable? No
- pass: $n-1$
- time complexity: $O(n^2)$
- space complexity: $O(1)$

## insertion Sort

![](../imgs/insertion_Sort.gif)

we still using the seq_list

```c
void insert_sort(seq_list *list){
    int i,j=1,k,temp;
    for (i = 0; i < list->n; i++)
    {
        if(list->elements[j]<list->elements[i]){
            temp = list->elements[j];
            slist_delete(list,j);
            for (k = i; temp < list->elements[k] && k > -1; k--);
            slist_insert(list,k,temp);   
        }
        j++;
    }
}
```

almost using the algorithm in abstract data type in sequence list

**Or limit the moving range**

```c
void insert_sort(seq_list *list){
    int i, j, temp;
    for (i = 1; i < list->n; i++)
    {
        temp = list->elements[i];
        for (j = i-1; j >=0; j--)
        {
            if(temp < list->elements[j])
                list->elements[j+1]=list->elements[j];
            else
                break;
        }
        list->elements[j+1] = temp;
    }
}
```

- stable? Yes
- pass: $n-1$
- time complexity: 
  - best: $n-1$
  - worst: $\sum^{n-1}_{i=1}i=\frac{n\times(n-1)}{2}$
  - average: $\sum^{n-1}_{i=1}(1+\frac{i}{2})=\frac{(n+4)(n-1)}{2}$
- space complexity: $O(1)$

## bubble sort

![](../imgs/Bubble.gif)

classic

```c
void bubble_sort(seq_list *list){
    int i,j;
    bool flag=false;
    while(flag!=true){
        flag=true;
        for (i = 0; i < list->n-1; i++)
        {
            if(list->elements[i] > list->elements[i+1]){
                swap(list->elements[i],list->elements[i+1]);
                flag=false;
            }
        }
    }
}
```

- stable? Yes
- pass: $n-1$
- time complexity: 
  - best: $n-1$
  - worst: $\sum^{n-1}_{i=1}i=\frac{n\times(n-1)}{2}$
  - average: $\frac{1}{n-1}\times\sum^{n-1}_{j=1}\sum^{n-1}_{i=1}(n-i)=\frac{n(2n-1)}{6}$
- space complexity: $O(1)$ (due to swap)

## quick sort

![](../imgs/quick.gif)

another classic sort algorithm, it's recursive, and fastest on average

1. get pivot

   ```c
   int partition(seq_list *list, int low, int high){
       int i = low, j = high + 1;
       int k = list->elements[low];
       do
       {
           do i++; while (i <= high && list->elements[i] < k);
           do j--; while (list->elements[j] > k);
           if(i < j) swap(list->elements[i],list->elements[j]);
       } while (i < j);
       if(low != j)
           swap(list->elements[low],list->elements[j]);
       return j;
   }
   ```

   first is to find the middle number, then swap its position with low,

   then origin `list[low]` is in the middle and left side element is smaller than this(called **pivot**) , right side element is bigger than pivot.

   if we starting with moving the `high` pointer, it can not using `do while` loop

   ```c
   int partition(seq_list *list, int low, int high){
       int i = low, j = high + 1;
       int k = list->elements[low];
       while(i < j){
           while(list->elements[--j] > k);
           while(i < j && list->elements[++i] < k);
           if(i < j)
               swap(list->elements[i],list->elements[j]);
       }
       if(low != j)
       swap(list->elements[low],list->elements[j]);
       return j;
   }
   ```

2. recursive sort

   ```c
   void q_sort(seq_list *list, int low, int high){
       int k;
       if(low < high){
           k = partition(list, low, high);
           q_sort(list, low, k-1);
           q_sort(list, k+1, high);
       }
   }
   ```

3. main_function

   ```c
   void quick_sort(seq_list *list){
       q_sort(list, 0, list->n-1);
   }
   ```

- stable? No
- pass: $Q(n)=Q(\lfloor\frac{n-1}{2}\rfloor)+Q(\lceil\frac{n+1}{2}\rceil)$ $Q(0)=Q(1)=0$
- time complexity: $O(n^2)$
- space complexity: $O(n)$ (due to recursive)

## merge sort

see the sequence has $n$ elements is consist by the $n$ sub-sequence elements.each time sort the sub-sequence.

obviously it has two steps: merge & sort.

1. Degree of n-like import order Subsequence Two individual length-like $n/2$ child order;
2. Opposite this two-individual order sort sort sort sort;
3. General two-individual expulsion-favorable child order Consolidation One-individual expulsion order.

![](../imgs/merge.gif)

merge

```c
void merge(seq_list *list, element_type *temp, int low, int len_l, int len_r){
    int i = low, j = low + len_l; //i,j index to first element in two sub-seq
    while(i < low + len_l && j < low + len_l + len_r){ //index in combine seq
        if(list->elements[i]<=list->elements[j])
            *temp++ = list->elements[i++]; //first is smallest
        else
            *temp++ = list->elements[j++];
    }
    //copy the rest element
    while(i < low + len_l)
        *temp++ = list->elements[i++];
    while(j < low + len_l + len_r)
        *temp++ = list->elements[j++];
}
```

temp is sorted element type sequence

the Sort

```c
void merge_sort(seq_list *list){
    element_type temp[list->n];
    int low, len_l, len_r, i, size = 1;
    while(size < list->n){  //sub-seq length not equal to seq
        low = 0;            //ever time start at `elements[0]`
        while(low + size < list->n){
            len_l = size;   //get left-seq length
            if(low + size * 2 < list->n )   //get right-seq length
                len_r = size;
            else
                len_r = list->n - low - size;
            merge(list, temp + low, low, len_l, len_r);
            low += len_l + len_r;           //get to next two sub-seqs
        }
        for (i = 0; i < low; i++)   //copy the element
            list->elements[i] = temp[i];
        size *= 2;
    }
}
```

- stable? Yes
- pass: $N=\lceil log_2n\rceil$
- time complexity: $O(n\times log_2n)$
- space complexity: $O(n)$ (due to store sub sequence)

## heap sort

<video src="https://vdn3.vzuu.com/SD/3bb38dfe-236a-11eb-8039-a6caf32b14c9.mp4?disable_local_cache=1&bu=078babd7&c=avc.0.0&f=mp4&expiration=1657161133&auth_key=1657161133-0-0-9aad2f380f8e0cba0d3db40de2dd74bf&v=tx&pu=078babd7"></video>

keep out put the top element on the heap

easy to implement it by using old codes

```c
void heap_srot(seq_list *list){
    prior_q *heap = (prior_q *)malloc(sizeof(prior_q));
    prior_q_create(heap, list->n);
    int i;
    for (i = 0; i < list->n; i++)
        prior_q_append(heap, list->elements[i]);
    for (i = 0; i < list->n; i++)
        priro_q_serve(heap,&list->elements[i]);
    prior_q_destroy(heap);
    free(heap);
}
```

- stable? No
- pass: $N=n-1$
- time complexity:
  - best & avg: $O(n\times log_2n)$
  - wrost: $O(n)$
- space complexity: $O(1)$

# Outside sort

It happend in large data want to sorted.There's no code implement here.

Omit.





