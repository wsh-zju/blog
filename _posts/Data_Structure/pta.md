---
layout: post
---



# PTA Homework Problems
## HW1 : time complexity
### 一、判断题
1. The major task of algorithm analysis is to analyze the time complexity and the space complexity.

    **Answer:** T

2. The Fibonacci number sequence \{$F_N$\}is defined as:$F_0=0,F_1=1,F_N=F_{N-1}+F_{N-2},N=2,3,...$The time complexity of the function which calculates $F_N$ recursively is $O(N!)$.
   
    **Answer:** F

    **Analysis:** 需要计算数列中的每一个数，时间复杂度为$O(N)$

3. $n^{0.01}$ is $O(\log n)$.

    **Answer:** F

    **Analysis:** 只要指数$a>0$，$n^a$在$n$增大时，最终都会比$\log n$大很多

4. For the following piece of code 
    ```c
    if ( A > B ){     
        for ( i=0; i<N*2; i++ )         
            for ( j=N*N; j>i; j-- )             
                C += A; 
    }
    else {     
        for ( i=0; i<N*N/100; i++ )         
            for ( j=N; j>i; j-- ) 
                for ( k=0; k<N*3; k++)
                    C += B; 
    }
    ```
    the **lowest upper bound** of the time complexity is $O(N^3)$.
    
    **Answer:** T
    
    **Analysis:** 第二个循环当 $i>=N$ 时，里边的循环不进行

### 二、单选题
1. Given the following four algorithms with their runtimes for problem size 100 and their time complexities:

    | Algorithm | Runtime | Time Complexity |
    | :--: | :--: | :--: |
    | A | 100 | $O(N)$ |
    | B | 50 | $O(N^2)$ |
    | C | 25 | $O(N^3)$ |
    | D | 10 | $O(N^4)$ |

    Which algorithm is the fastest for problem size 200?

    **Answer:** A

    **Analysis:** 根据时间复杂度得到数据增多到200时，运行时间增多的倍数

2. Let $n$ be a non-negative integer representing the size of input.  The time complexity of the following piece of code is:
    ```c
    x = 0;
    while ( n >= (x+1)*(x+1) )
        x = x+1;
    ```
    
    **Answer:** $O(n^{1/2})$

3. \* **The recurrent equations for the time complexities of programs P1 and P2 are:**

    P1:$T(1)=1,T(N)=T(N/3)+1$

    P2:$T(1)=1,T(N)=3T(N/3)+1$

    **Then the correct conclusion about their time complexities is:**

    A. they are both $O(\log N)$

    B. $O(\log N)$ for P1,$O(N)$ for P2

    C. they are both $O(N)$

    D. $O(\log N)$ for P1,$O(N\log N)$ for P2

    **Answer:** B
    
    **Analysis:** 
    
    P1:进行多次迭代，$k$次迭代后得到$T(N)=T(\frac{N}{3^k})+k$，当$\frac{N}{3^k}=1$，即$k=\log_3 n$，$T(N)=T(1)+\log_3 n=O(\log n)$

    P2:进行多次迭代，$k$次迭代后得到
    $$
    T(N)=3^kT(\frac{N}{3^k})+\sum_{i=0}^{k-1}{3^i}
    $$
    当$\frac{N}{3^k}=1$，即$k=\log_3 n$ 
    $$
    T(N)=NT(1)+\frac{N-1}{2}=O(\log n)
    $$

## HW2 : linear list
### 一、判断题
1. \* **For a sequentially stored linear list of length $N$, the time complexities for deleting the first element and inserting the last element are $O(1)$ and $O(N)$, respectively.**

    **Answer:** F
    
    **Analysis:** sequentially stored linear list（顺序存储）=Array
    
    ??? abstract "线性表" 

        线性表（按存储结构分）：

        - 顺序存储：数组  

            删除第一个元素，需要将后边的元素都往前移一位，时间复杂度为$O(N)$. 

        - 链式存储：链表（单向链表、双向链表、循环链表）
        
2. If a linear list is represented by a linked list, the addresses of the elements in the memory must be consecutive **(连续的)**.

    **Answer:** F

### 二、单选题
1. To merge two singly linked ascending **(升序)** lists, both with N nodes, into one singly linked ascending list, the minimum possible number of comparisons is:

    A. 1

    B. $N$

    C. $2N$

    D. $N\log N$

    **Answer:** B
    
    **Analysis:** 考虑极端情况：第一个链表的数据都小于第二个链表

### 三、函数题  
#### \*Reverse Linked List

Write a nonrecursive procedure to reverse a singly linked list in $O(N)$ time using constant extra space.

**Format of functions:**
    ```c
    List Reverse( List L );
    ```
where `List` is defined as the following:
    ```c
    typedef struct Node *PtrToNode;
    typedef PtrToNode List;
    typedef PtrToNode Position;
    struct Node {
        ElementType Element;
        Position Next;
    };
    ```
The function `Reverse` is supposed to return the reverse linked list of `L`, with a dummy header.

**Sample program of judge:**
    ```c
    #include <stdio.h>
    #include <stdlib.h>

    typedef int ElementType;
    typedef struct Node *PtrToNode;
    typedef PtrToNode List;
    typedef PtrToNode Position;
    struct Node {
        ElementType Element;
        Position Next;
    };

    List Read(); /* details omitted */
    void Print( List L ); /* details omitted */
    List Reverse( List L );

    int main()
    {
        List L1, L2;
        L1 = Read();
        L2 = Reverse(L1);
        Print(L1);
        Print(L2);
        return 0;
    }

    /* Your function will be put here */
    ```
**Sample Input:**

    5
    1 3 4 5 2

**Sample Output:**

    2 5 4 3 1
    2 5 4 3 1

**Answer Code**
    ```c
    List Reverse( List L ){
        List p,q,k;
        p=NULL;
        q=L->Next;
        while(q!=NULL){ 
            k=q->Next;
            q->Next=p;
            p=q;
            q=k;
        }
        L->Next=p;
        return L;
    }
    ```
## HW3 : stack
### 一、判断题
1. Push 5 characters `ooops` onto a stack.  In how many different ways that we can pop these characters and still obtain `ooops`?

    A. 1

    B. 3

    C. 5

    D. 6

    **Answer:** C

2. Suppose that an array of size 6 is used to store a circular queue, and the values of `front` and `rear` are 0 and 4, respectively.  Now after 2 dequeues and 2 enqueues, what will the values of `front` and `rear` be?

    A. 2 and 0

    B. 2 and 2

    C. 2 and 4

    D. 2 and 6

    **Answer:** A

    **Analysis:** `front` 表示队头元素的位置；`rear` 表示队尾元素的下一个位置

### 二、编程题
#### Pop Sequence

Given a stack which can keep M numbers at most.  Push N numbers in the order of 1, 2, 3, ..., N and pop randomly.  You are supposed to tell if a given sequence of numbers is a possible pop sequence of the stack.  For example, if M is 5 and N is 7, we can obtain 1, 2, 3, 4, 5, 6, 7 from the stack, but not 3, 2, 1, 7, 5, 6, 4.

**Input Specification:**

Each input file contains one test case.  For each case, the first line contains 3 numbers (all no more than 1000): M (the maximum capacity of the stack), N (the length of push sequence), and K (the number of pop sequences to be checked).  Then K lines follow, each contains a pop sequence of N numbers.  All the numbers in a line are separated by a space.

**Output Specification:**

For each pop sequence, print in one line "YES" if it is indeed a possible pop sequence of the stack, or "NO" if not.

**Sample Input:**

    5 7 5
    1 2 3 4 5 6 7
    3 2 1 7 5 6 4
    7 6 5 4 3 2 1
    5 6 4 3 7 2 1
    1 7 6 5 4 3 2
**Sample Output:**

    YES
    NO
    NO
    YES
    NO
    
**Answer Code**
    ```c
    #include <stdio.h>

    int main(){
        int m,n,k;
        scanf("%d %d %d",&m,&n,&k);
        for(int i=0;i<k;i++){
            int a[n];
            int test=1;
            for(int j=0;j<n;j++){
                scanf("%d",&a[j]);
            }
            int b[1000];    //模拟堆栈
            int top=0,max=0;    //top:堆栈中的元素个数;max:目前堆栈中出现过的最大的数
            for(int j=0;j<n;j++){
                for(int x=max+1;x<a[j]+1;x++){
                    max++;
                    b[top++]=max;   //让比max大的且小于等于当前元素的数字入栈
                }
                if(top>m||b[top-1]>a[j]){
                    test=0;     //如果堆栈中的元素个数大于容纳量或者最后一个元素比当前元素大，结果错误
                }else{
                    top--;  //弹出最后一个元素
                }
            }
            if(test==0){
                printf("NO\n");
            }else{
                printf("YES\n");
            }
        }
    }
    ```
## HW4 : tree
### 一、判断题
1. There exists a binary tree with 2016 nodes in total, and with 16 nodes having only one child.

    **Answer:** F

    **Analysis:** 参照note中的公式

### 二、单选题
1. If a general tree T is converted into a binary tree BT, then which of the following BT traversals gives the same sequence as that of the post-order traversal of T?

    A. Pre-order traversal

    B. In-order traversal

    C. Post-order traversal

    D. Level-order traversal

    **Answer:** B

    **Analysis:** T->BT:第一个子节点作为左子节点，下一个兄弟节点作为右子节点

2. \* **Among the following threaded binary trees (the threads are represented by dotted curves), which one is the postorder threaded tree **(后序线索二叉树)**?**

    A.![](photo/HW4-1.png)    

    B.![](photo/HW4-2.png)

    C.![](photo/HW4-3.png)

    D.![](photo/HW4-4.png)

    **Answer:** B

    
    ??? abstract "后续线索二叉树" 
        
        后序线索二叉树

        - 定义：在二叉树的基础上，通过线索化处理，利用二叉树中节点的空指针域来存放节点在后序遍历序列中的前驱和后继信息

        - 规则：如果一个节点没有左子节点，那么其左指针域指向它在后序遍历中的前驱；如果一个节点没有右子节点，那么其右指针域指向它在后序遍历中的后继

### 三、函数题
#### Isomorphic

内容：判断两个二叉树是不是同构的

思路：利用递归

**Answer Code**
    ```c
    int Isomorphic( Tree T1, Tree T2 ){
        Tree f,g;
        f=T1;g=T2;
        if(f&&g){
            if(f->Element!=g->Element){
                return 0;
            }else{
                int a,b,c,d;
                a=Isomorphic(f->Left,g->Right);
                b=Isomorphic(f->Right,g->Left);
                c=Isomorphic(f->Left,g->Left);
                d=Isomorphic(f->Right,g->Right);
                if((a&&b)||(c&&d)){
                    return 1;
                }else{
                    return 0;
                }
            }
        }else if(f==NULL&&g==NULL){
            return 1;
        }else{
            return 0;
        }
    }
    ```
### 四、编程题
#### ZigZagging on a tree
Suppose that all the keys in a binary tree are distinct positive integers.  A unique binary tree can be determined by a given pair of postorder and inorder traversal sequences.  And it is a simple standard routine to print the numbers in level-order.  However, if you think the problem is too simple, then you are too naive.  This time you are supposed to print the numbers in "zigzagging order" -- that is, starting from the root, print the numbers level-by-level, alternating between left to right and right to left.  For example, for the following tree you must output: 1 11 5 8 17 12 20 15.

![](photo/HW4-zag.png)

**Input Specification:**

Each input file contains one test case.  For each case, the first line gives a positive integer N (≤30), the total number of nodes in the binary tree.  The second line gives the inorder sequence and the third line gives the postorder sequence.  All the numbers in a line are separated by a space.

**Output Specification:**

For each test case, print the zigzagging sequence of the tree in a line.  All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.

**Sample Input:**

    8
    12 11 20 17 1 15 8 5
    12 20 17 11 15 8 5 1

**Sample Output:**

    1 11 5 8 17 12 20 15

内容：根据中序遍历和后序遍历，Z字形遍历二叉树

思路：level表示当前遍历的下一行：如果level为奇数，从左到右遍历当前层的节点，输出节点值，并将子节点存入数组c中；如果level为偶数，从右到左遍历当前层的节点，输出节点值，并将子节点存入数组c中

**Answer Code**
    ```c
    #include <stdio.h>
    #include <math.h>
    #include <stdlib.h>
    typedef struct node{
        int num;
        struct node *left;
        struct node *right;
    }node;
    /*构造二叉树*/
    void struc(int a[],int b[],int st1,int ed1,int st2,int ed2,node *p){
        if(st1<ed1+1){
            p->num=b[ed2];
            int k=0;
            for(int i=st1;i<ed1+1;i++){
                if(a[i]==b[ed2]){
                    break;
                }
                k++;
            }
            p->left=malloc(sizeof(struct node));
            p->right=malloc(sizeof(struct node));
            struc(a,b,st1,st1+k-1,st2,st2+k-1,p->left);
            struc(a,b,st1+k+1,ed1,st2+k,ed2-1,p->right);
        }else{
            p=NULL;
        }
    }

    int main(){
        int n;
        scanf("%d",&n);
        int a[n],b[n];
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++){
            scanf("%d",&b[i]);
        }
        node *q;
        q=malloc(sizeof(struct node));
        struc(a,b,0,n-1,0,n-1,q);
        int size=n*n;
        node *c[size];
        c[0]=q;
        int st=0;
        int ed=1;
        int max=1;
        int level=2;
        printf("%d",q->num);
        while(max<=size){
            if(level%2){
                for(;st<ed;st++){
                    if(c[st]){
                        if(c[st]->num)printf(" %d",c[st]->num);
                        c[max++]=c[st]->left;
                        c[max++]=c[st]->right;
                    }
                }
                ed=max;
            }else{
                max=max+n;
                int temp=max-1;
                for(;ed>st;ed--){
                    if(c[ed-1]){
                        if(c[ed-1]->num&&level!=2) printf(" %d",c[ed-1]->num);
                        c[temp--]=c[ed-1]->right;
                        c[temp--]=c[ed-1]->left;
                    }
                }
                ed=max;
                st=temp+1;
            }
            level++;
        }
        printf("\n");
    }
    ```
## HW5 : binary search tree
### 一、判断题
1. In a binary search tree, the keys on the same level from left to right must be in sorted (non-decreasing) order.

    **Answer:** T

2. \* **In a binary search tree which contains several integer keys including 4, 5, and 6, if 4 and 6 are on the same level, then 5 must be their parent.**

    **Answer:** F

    **Analysis:** 例如下边的二叉树：

             5
           /    \
          3      7
         /  \   /  \
        2    4 6    8

### 二、单选题
1. \* **Given a binary search tree with its preorder traversal sequence { 8, 2, 15, 10, 12, 21 }.  If 8 is deleted from the tree, which one of the following statements is `FALSE`?**

    A. One possible preprder traversal sequence of the resulting tree may be { 2, 15, 10, 12, 21 }

    B. One possible preprder traversal sequence of the resulting tree may be { 10, 2, 15, 12, 21 }

    C. One possible preprder traversal sequence of the resulting tree may be { 15, 10, 2, 12, 21 }

    D. It is possible that the new root may have 2 children

    **Answer:** C

2. \* **Among the following binary trees, which one can possibly be the decision tree (二分查找的判定树)(the external nodes are excluded) for binary search?**
   
    A.![](photo/HW5-1.png) 

    B.![](photo/HW5-2.png)

    C.![](photo/HW5-3.png)

    D.![](photo/HW5-4.png)

    **Answer:** A
    
    **Analysis:** B选项4、5相加除二向上取整，7、8相加除二向下取整，矛盾。C选项，3、4相加除二向上取整，6、7相加除二向下取整，矛盾。D选项，1、10相加除二向下取整，6、7相加除二向上取整，矛盾。A符合折半查找规则，正确。
    
    ??? abstract "二分查找判定树" 

        二分查找判定树的特点

         - 它是一棵二叉排序树（二叉搜索树），对于树中任意节点，其左子树节点值小于该节点值，右子树节点值大于该节点值

         - 树的形态要符合二分查找过程中对区间不断划分的逻辑

## HW6 : complete binary tree & min/max-heap
### 一、判断题
1. If a complete binary tree with 137 nodes is stored in an array (root at position 1), then the nodes at positions 128 and 137 are at the same level.
    
    **Answer:** T

2. The inorder traversal sequence of any min-heap must be in sorted order.
    
    **Answer:** F

    
    ??? abstract "二叉堆" 

        二叉堆：一种特殊的完全二叉树

         - 最小堆
             每个节点的值小于等于其子节点的值，根节点是整个堆中的最小值 
         
         - 最大堆
             每个节点的值大于等于其子节点的值，根节点是整个堆中的最大值

### 二、单选题
1. \* **In a max-heap with n (>1) elements, the array index of the minimum key may be ____.**

    A. 1

    B. $\lfloor \frac{n}{2} \rfloor$-1

    C. $\lfloor \frac{n}{2} \rfloor$

    D. $\lfloor \frac{n}{2} \rfloor$+2

    **Answer:** D

    **Analysis:** 最大堆的最小元素一般在叶节点上

2. \* **Using the linear algorithm to build a min-heap from the sequence {15, 26, 32, 8, 7, 20, 12, 13, 5, 19}, and then insert 6.  Which one of the following statements is FALSE?**

    A. The root is 5

    B. The path from the root to 26 is {5, 6, 8, 26}

    C. 32 is the left child of 12

    D. 7 is the parent of 19 and 15

    **Answer:** C

    
    ??? abstract "Buildheap" 

        Buildheap 构建堆的方式

         1. 先将给定序列按照完全二叉树的结构存储
         
         2. 从最后一个**非叶子节点**开始进行下沉操作，下沉时保证父节点小于等于子节点
         
         注意：与插入操作区别开！具体事例参见note

3. \* **If a d-heap is stored as an array, for an entry located in position i, the parent, the first child and the last child are at:**

    A. $\lceil \frac{i+d−2}{d} \rceil$, $(i−2)d+2$, and $(i−1)d+1$

    B. $\lceil \frac{i+d−1}{d} \rceil$, $(i−2)d+1$, and $(i−1)d$

    C. $\lfloor \frac{i+d−2}{d} \rfloor$, $(i−1)d+2$, and $id+1$

    D. $\lfloor \frac{i+d−1}{d} \rfloor$, $(i−1)d+1$, and $id$

    **Answer:** C

    **Analysis:** 可以根据二叉树分析
    > d-heap : d叉树
4. If a binary search tree of $N$ nodes is complete, which one of the following statements is `FALSE`?

    A. the average search time for all nodes is $O(\log N)$

    B. the minimum key must be at a leaf node

    C. the maximum key must be at a leaf node

    D. the median node must either be the root or in the left subtree

    **Answer:** C

### 三、函数题
**Percolate Up and Down**

内容：对一个二叉最小堆做上浮和下沉操作


??? abstract "Percolate Up and Down" 

    Percolate Up and Down

     - Percolate Up

         当向堆中**插入**一个新元素时，新元素被添加到堆的末尾（数组的最后一个位置），此时可能会破坏堆的性质，需要通过上浮操作将新元素移动到合适的位置，以恢复堆的性质
     
     - Percolate Down
         
         当从堆中**删除**根节点（最大堆中的最大值或最小堆中的最小值）时，通常将堆的最后一个元素移动到根节点的位置，此时可能会破坏堆的性质，需要通过下沉操作将新的根节点移动到合适的位置，以恢复堆的性质

### 四、函数题
**Complete Binary Search Tree**

内容：根据已知序列构建完全二叉查找树（唯一）

**Answer Code**
    ```c
    /*构建完全二叉查找树的函数（保证序列已经是有序序列）*/
    void build(int a[],int b[],int s,int e,int p){
        if(s<=e){
            int size=e-s+1;
            int k=1;
            for(;k<=size;k=k*2){}
            k=k/2;
            int index=e-((k/2-1)+(size-(k-1)<=k/2?0:(size-k+1-k/2)));  //重点！！！（判断根节点在数组中的索引）
            b[p]=a[index];
            build(a,b,s,index-1,2*p);
            build(a,b,index+1,e,2*p+1);
        }
    }
    ```
## HW7 : ADT ( disjoint set )
### 一、判断题
1. In Union/Find algorithm, if Unions are done by size, the depth of any node must be no more than $\frac{N}{2}$, but not $O(\log N)$. 

    **Answer:** F
    
    **Analysis:** Union by size:树的高度为$O(\log n)$，树的高度满足公式：
    $$
    height(T) \leq \lfloor \log_2 n \rfloor +1
    $$

### 二、单选题
1. The array representation of a disjoint set containing numbers 0 to 8 is given by { 1, -4, 1, 1, -3, 4, 4, 8, -2 }.  Then to union the two sets which contain 6 and 8 (with union-by-size), the index of the resulting root and the value stored at the root are:

    A. 1 and -6

    B. 4 and -5

    C. 8 and -5

    D. 8 and -6

    **Answer:** B

2. A relation $R$ is defined on a set $S$.  If for every element $e$ in $S$, "$e R e$" is always true, then $R$ is said to be ____ over $S$.

    A. consistent **(一致的)**

    B. symmetric **(对称的)**

    C. transitive **(传递的)**

    D. reflexive **(自反的)**

    **Answer:** D

### 三、程序填空题
1. Please fill in the blanks in the program which performs `Find` as a Union/Find operation with path compression **(路径压缩功能)**.

    **思路**：在查找过程中，将路径上的节点直接指向根节点，从而减少后续查找操作的时间复杂度
        ```c
        SetType Find ( ElementType X, DisjSet S ){   
            ElementType root, trail, lead;
            for ( root = X; S[root] > 0; _root=S[root]_ ) ;  
            for ( trail = X; trail != root; trail = lead ) {
                lead = S[trail] ;   
                _S[trail]=root_;   
            } 
            return root;
        }
        ```
### 四、编程题
**File Transfer** ( 不在此赘述 )

内容：利用ADT判断两台计算机之间是否可以传输数据

## HW8 : graph
### 一、判断题
1. \* **In a connected graph, the number of edges must be greater than the number of vertices minus **(减)** 1.**

    **Answer:** F

    **Analysis:** 如果是树 **（连通且无环的图）**，边的数量等于顶点数减一；连通图存在环时，边的数量大于顶点数减一

2. In a directed graph, the sum of the in-degrees must be equal to the sum of the out-degrees of all the vertices.

    **Answer:** T

3. If a directed graph $G=(V, E)$ is weakly connected, then there must be at least $|V|$ edges in $G$.

    **Answer:** F

    **Analysis:** 考虑无向树，边数为$|V|-1$

### 二、单选题
1. If graph $G$ is NOT connected and has 35 edges, then it must have at least ____ vertices.

    A. 7

    B. 8

    C. 9

    D. 10

    **Answer:** D

2. A graph with 90 vertices and 20 edges must have at least ____ connected component(s).

    A. 69

    B. 70

    C. 84

    D. 85

    **Answer:** B

3. Given the adjacency list of a directed graph as shown by the figure.  There is(are) ____ strongly connected component(s).
   
    ![](photo/HW8-1.png)

    A. 4 \{\{0, 1, 5\}, \{2\}, \{3\}, \{4\}\}
    
    B. 3 \{\{2\}, \{4\}, \{0, 1, 3, 5\}\} 
    
    C. 1 \{0, 1, 2, 3, 4, 5\}
    
    D. 1 \{0, 5, 1, 3\}
    
    **Answer:** B

4. Given an undirected graph $G$ with 16 edges, where 3 vertices are of degree 4, 4 vertices are of degree 3, and all the other vertices are of degrees less than 3.  Then $G$ must have at least ____ vertices.

    A. 10

    B. 11

    C. 13

    D. 15

    **Answer:** B

5. Which one of the following is NOT a topological order **(拓扑排序)** of the given directed graph shown by the figure?

    ![](photo/HW8-2.png)

    A. 1, 5, 2, 3, 6, 4
    
    B. 5, 1, 2, 6, 3, 4
    
    C. 5, 1, 2, 3, 6, 4
    
    D. 5, 2, 1, 6, 3, 4
    
    **Answer:** D

### 三、函数题
**Is topological order?** 

内容：判断是否是拓扑排序的顺序

### 四、编程题
**Hamiltonian Cycle**

内容：判断是否是哈密顿回路（指一条经过图中每个顶点恰好一次，并且最终回到起始顶点的路径）

## Mid Term

!!! note "Notice!"
    均为考试中错误的题目，需认真对待！！！

### 一、判断题

1. If a tree is created by union-by-size with $n$ nodes, then each element can have its set name changed at most $\log n$ times.
   
   **Answer:** T

2. Linear list is a data structure that represents many-to-1 relations.

    **Answer:** F

    **Analysis:** 线性表中的元素是一对一的线性关系，即每个元素都有唯一的前驱和后继。多对一关系常见于树形结构等。

### 二、单选题

1. There are 8 leaf nodes on the sixth level of a complete binary tree.  Suppose that the root is on the first level, then how many nodes does the complete binary tree have at most?

    A.39

    B.52

    C.79

    D.111

    **Answer:** D

    **Analysis:** 前六层全满，1+2+4+8+16+32+64-16=111

2. Which of the following statements is `FALSE`?

    A.A directed acyclic gragh **(有向无环图)** must be a tree.

    B.There must be no topological order in a directed graph with a cycle.

    C.Topological sorting method can be used to check if there is a cycle in a given directed graph.

    D.Partial order **(偏序关系)**is a precedence relation which is both transitive and irreflexive.

    **Answer:** A

    **Analysis:** A：有向无环图（DAG）不一定是树。树要求每个节点（除根节点外）有且仅有一个入边，而有向无环图只要求没有环，节点入边情况更为灵活，比如可以存在多个节点没有入边等情况

    ??? abstract "偏序关系"
        - 定义：偏序关系（Partial Order Relation）是集合论中的一个重要概念，用于描述集合中元素之间的顺序关系，是在一个集合上定义的一种二元关系，通常用符号$≤$表示
        - 满足自反性，反对称性，传递性

### 三、程序填空题

!!! note "Notice!"
    - 一定要输对变量的名称！！！
    - 注意下一道题中传入函数的数组如何表示！

1. Build Tree from Inorder and Preorder Traversals

    The function BuildTree is to build and return a binary tree from its inorder and preorder traversal sequences.

    The tree structure is defined as the following:
        ```c
        typedef struct Node *PtrToNode;
        struct Node{
            int Data;
            PtrToNode Left, Right;
        };
        typedef PtrToNode Tree;
        ```
     Please fill in the blanks.
        ```c
        Tree BuildTree( int in[], int pre[], int N ){ 
            //in[] stores the inorder traversal sequence 
            //and pre[] stores the preorder traversal sequence
            //N is the number of nodes in the tree
            Tree T;
            int i;
            if (!N) {
                return NULL;
            }
            T = (Tree)malloc(sizeof(struct Node));
            T->Data = _pre[0]_;
            for (i=0; i<N; i++)
                if (in[i]==T->Data) break;
            T->Left = BuildTree(_in,pre+1,i_);
            T->Right = BuildTree(_in+i+1,pre+i+1,N-i-1_);
            return T;
        }  
        ```

## HW9 : Shortest Path Algorithms
### 一、判断题
1. Let $P$ be the shortest path from $S$ to $T$. If the weight of every edge in the graph is incremented by 2, $P$ will still be the shortest path from $S$ to $T$.

   **Answer:** F
   **Analysis:** 还与经过的边的个数有关，边的个数较多时可能不是最短路径  

### 二、单选题
1. Use Dijkstra algorithm to find the shortest paths from 1 to every other vertices.  In which order that the destinations must be obtained?

    ![](photo/HW9-1.png)

    A. 2, 5, 3, 4, 6, 7

    B. 2, 4, 3, 6, 5, 7

    C. 2, 3, 4, 5, 6, 7

    D. 5, 2, 6, 3, 4, 7

    **Answer:** B


## HW10 : Network Flow & Minimum Spanning Tree
### 一、单选题
1. The minimum spanning tree of any weighted graph ____

    A.must be unique

    B.must not be unique

    C.exists but may not be unique

    D.may not exist

    **Answer:** D
    
    **Analysis:** 非连通图不存在最小生成树

2. The maximum flow in the network of the given Figure is:
    
    ![](photo/HW10-1.png)

    A.104

    B.123

    C.120

    D.97

    **Answer:** A

### 二、编程题
!!! note "Notice!"
    都很难！！！

#### 最大流问题

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 0x3f3f3f3f // 定义一个很大的数，用于表示无穷大，在最大流算法中表示初始的流量上限
// 将由大写字母组成的字符串转换为一个整数值
// 转换方式是基于26进制，每个字母对应一个数值（A对应0，B对应1，以此类推）
int to_int(char *str) {
    int ans = 0;
    for (int i = 0; i < strlen(str); i++) {
        ans = ans * 26 + str[i] - 'A';
    }
    return ans;
}
int s, t; // 定义源点s和汇点t，用于最大流算法
// 定义边的结构体，每条边包含目标节点r和边的容量w
struct Line {
    int r;
    int w;
} line[1005];
int g[30000][1005]; // 邻接表，用于存储图的边信息，g[i][j] 表示节点i的第j条边在line数组中的索引
int g_cnt[30000]={0}; // 记录每个节点的边的数量，g_cnt[i] 表示节点i的边的数量
int deep[30000]; // 用于记录节点在分层图中的深度
// 广度优先搜索（BFS）构建分层图
// 若能找到从源点s到汇点t的路径，则返回1，否则返回0
int bfs() {
    int que[30000]; // 用数组模拟队列，用于BFS遍历
    int front = 0, rear = 0; // 队列的头指针和尾指针
    memset(deep, 0, sizeof(deep)); // 将所有节点的深度初始化为0
    que[rear++] = s; // 将源点s加入队列
    deep[s] = 1; // 源点的深度设为1
    while (front < rear) { // 队列不为空时循环
        int top = que[front++]; // 取出队首元素
        for (int i = 0; i < g_cnt[top]; i++) { // 遍历当前节点的所有边
            int z = g[top][i]; // 获取当前边在line数组中的索引
            // 如果目标节点未被访问过（深度为0）且该边的容量大于0
            if (!deep[line[z].r] && line[z].w) {
                deep[line[z].r] = deep[top] + 1; // 设置目标节点的深度
                que[rear++] = line[z].r; // 将目标节点加入队列
                // 如果找到了汇点t，说明存在从源点到汇点的路径，返回1
                if (deep[t])
                    return 1;
            }
        }
    }
    return 0; // 遍历完所有节点后仍未找到汇点，返回0
}
// 深度优先搜索（DFS）在分层图中寻找增广路径并更新流量
// x 是当前节点，mix 是当前路径上的最小剩余容量
// 返回值是通过该路径能够增加的流量
int dfs(int x, int mix) {
    if (x == t ||!mix) // 如果到达汇点或者剩余容量为0，则返回当前剩余容量
        return mix;
    int ap = 0; // 记录通过当前节点的增广路径增加的流量
    for (int i = 0; i < g_cnt[x]; i++) { // 遍历当前节点的所有边
        int z = g[x][i]; // 获取当前边在line数组中的索引
        // 如果目标节点的深度大于当前节点的深度且该边的容量大于0
        if (deep[x] < deep[line[z].r] && line[z].w) {
            int p;
            // 根据当前路径剩余容量和边的容量取较小值作为递归调用的参数
            //为了找到这条路径上的实际流量
            if (mix < line[z].w)
                p = dfs(line[z].r, mix);
            else
                p = dfs(line[z].r, line[z].w);
            ap += p; // 累加通过该路径增加的流量
            mix -= p; // 减少当前路径剩余容量
            line[z].w -= p; // 减少正向边的容量
            line[z+1].w += p; // 增加反向边的容量
            if (!mix) // 如果当前路径剩余容量为0，返回已经增加的流量
                return ap;
        }
    }
    return ap; // 遍历完所有边后，返回通过当前节点的增广路径增加的流量
}
// Dinic算法的主函数，计算最大流
// 返回值是从源点到汇点的最大流
int dinic() {
    int ans = 0;
    while (bfs()) { // 不断构建分层图，直到无法找到从源点到汇点的路径
        ans += dfs(s, INF); // 在分层图中寻找增广路径并更新最大流
    }
    return ans;
}
int main() {
    char str1[4], str2[4]; // 用于存储输入的源点和汇点的字符串
    int m; // 边的数量
    scanf("%s %s %d", str1, str2, &m);
    s = to_int(str1); // 将源点字符串转换为整数值
    t = to_int(str2); // 将汇点字符串转换为整数值
    for (int i = 0; i < m; i++) { // 读取每条边的信息
        char strx[4], stry[4]; // 用于存储边的起点和终点的字符串
        int w; // 边的容量
        scanf("%s %s %d", strx, stry, &w); // 读取边的起点、终点和容量
        int a = to_int(strx); // 将起点字符串转换为整数值
        int b = to_int(stry); // 将终点字符串转换为整数值
        line[2 * i].r = b; // 正向边的目标节点
        line[2 * i].w = w; // 正向边的容量
        line[2 * i + 1].r = a; // 反向边的目标节点
        line[2 * i + 1].w = 0; // 反向边的初始容量为0
        g[a][g_cnt[a]++] = 2 * i; // 将正向边加入邻接表
        g[b][g_cnt[b]++] = 2 * i + 1; // 将反向边加入邻接表
    }
    printf("%d\n", dinic()); // 计算并输出最大流
}
```

[点击查看C语言代码](code_docu/HW10-1.c)

## HW11 : DFS
### 一、判断题
1. For a graph, if each vertex has an even degree or only two vertexes have odd degree, we can find a cycle that visits every edge exactly once.

    **Answer:** F
    
    **Analysis:** 存在欧拉路径，不存在欧拉回路

2. After the first run of Insertion Sort, it is possible that no element is placed in its final position.  

    **Answer:** T
    
    **Analysis:** 题目所问：是否存在某种输入数组，使得第一轮运行后，所有元素都不在它们的最终位置上。e.g.逆序数组 $[3,2,1]$

### 二、选择题
1. **Apply DFS to a directed acyclic graph, and output the vertex *before the end of each recursion*.  The output sequence will be:**

    A.unsorted

    B.topologically sorted

    C.reversely topologically sorted

    D.None of the above

    **Answer:** C

2. Use simple insertion sort to sort 10 numbers from non-decreasing to non-increasing, the possible numbers of comparisons and movements are:

    A.100, 100

    B.100, 54

    C.54, 63

    D.45, 44

    **Answer:** D

### 三、函数题

#### 强连通图（difficult）
```c
void StronglyConnectedComponents(Graph G, void (*visit)(Vertex V)) {
    int visited[G->NumOfVertices];
    int stack[G->NumOfVertices];
    int index=0;
    for(int i=0;i<G->NumOfVertices;i++){
        visited[i]=0;
    }
    for (int i=0; i < G->NumOfVertices; i++) {
        if (!visited[i]) {
            int dfsStack[G->NumOfVertices];
            int num=0;
            dfsStack[num++] = i;
            visited[i] = 1;
            while (num>0) {
                int v=dfsStack[num-1];
                PtrToVNode node = G->Array[v];
                int pushed=0;
                while (node) {
                    int a=node->Vert;
                    if (!visited[a]) {
                        dfsStack[num++] = a;
                        visited[a] = 1;
                        pushed = 1;
                        break;
                    }
                    node = node->Next;
                }
                if (!pushed) {
                    stack[index++] = v;
                    num--;
                }
            }
            /*for(int j=0;j<index;j++){
                printf("%d ",stack[j]);
            }
            printf("\n");*/
        }
    }
    Graph Q= (Graph)malloc(sizeof(struct GNode));
    Q->NumOfVertices = G->NumOfVertices;
    Q->NumOfEdges = G->NumOfEdges;
    Q->Array = (PtrToVNode *)malloc(G->NumOfVertices * sizeof(PtrToVNode));
    for (int i = 0; i < G->NumOfVertices; i++) {
        Q->Array[i] = NULL;
    }
    //构建转置图
    for (int i = 0; i < G->NumOfVertices; i++) {
        PtrToVNode node = G->Array[i];
        while (node) {
            int v = node->Vert;
            PtrToVNode newNode = (PtrToVNode)malloc(sizeof(struct VNode));
            newNode->Vert = i;
            newNode->Next = Q->Array[v];
            Q->Array[v] = newNode;
            node = node->Next;
        }
    }
    for(int i=0;i<G->NumOfVertices;i++){
        visited[i]=0;
    }
    while (index > 0) {
        int v = stack[--index];
        if (!visited[v]) {
            int sccStack[G->NumOfVertices];
            int sccStackIndex = 0;
            sccStack[sccStackIndex++] = v;
            visited[v] = 1;
            while (sccStackIndex > 0) {
                int current = sccStack[--sccStackIndex];
                visit(current);
                PtrToVNode node = Q->Array[current];
                while (node != NULL) {
                    int a = node->Vert;
                    if (!visited[a]) {
                        sccStack[sccStackIndex++] = a;
                        visited[a] = 1;
                    }
                    node = node->Next;
                }
            }
            printf("\n");
        }
    }
}
```

## HW12 : Sort1
### 一、判断题
1. Shell sort is stable.

    **Answer:** F

2. Mergesort is stable.  

    **Answer:** T

    **Analysis:** 稳定排序算法要求相等元素的相对顺序在排序前后保持不变

## HW13 ：Sort2
### 一、判断题
1. **During the sorting, processing every element which is not yet at its final position is called a "run". To sort a list of integers using quick sort,  it may reduce the total number of recursions by processing the small partion first in each run.**

    **Answer:** F

2. If there are less than 20 inversions in an integer array, the Quick Sort will be the best method among Quick Sort, Heap Sort and Insertion Sort.  

    **Answer:** F

    **Analysis:** 序列基本有序，插入排序的时间复杂度近似于 $O(N)$

### 二、单选题
1. **During the sorting, processing every element which is not yet at its final position is called a "run". Which of the following cannot be the result after the second run of quicksort?**

    A.5, 2, 16, 12, 28, 60, 32, 72

    B.2, 16, 5, 28, 12, 60, 32, 72

    C.2, 12, 16, 5, 28, 32, 72, 60

    D.5, 2, 12, 28, 16, 32, 72, 60

    **Answer:** D

    **Analysis:** 第一次排序，第一次的基准到达最终位置；第二次排序，第二次的两个基准到达最终位置。最终一共有三个到达最终位置（注：如果第一次基准在最前或最后，则只有两个到达最终位置）

## HW14 : Hash1
### 一、单选题
1. Which of the following statements about HASH is true?

    A.the expected number of probes for insertions is greater than that for successful searches in linear probing method

    B.if the table size is prime and the table is at least half empty, a new element can always be inserted with quadratic probing

    C.in separate chaining method, if duplicate elements are allowed in the list, insertions are generally quicker than deletions 

    D.all of the above

    **Answer:** D

### 二、编程题
#### 还原哈希表插入序列
- 给定一个哈希表的最终状态（包含部分空位置），要求还原原始的插入序列
- 哈希表使用线性探测解决冲突
- 且在插入时若存在多个可选数字，优先选择最小的

```c
```