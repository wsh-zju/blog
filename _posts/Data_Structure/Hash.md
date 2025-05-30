---
layout: post
---


## 哈希表
### 相关定义
1. 哈希函数

$f(x)=x在ht[ ]中的位置$

2. $T=x可能取值的个数$ 

3. $n=ht[ ]中标识符的个数$

4. 标识符密度（Identifier density）= $\frac{n}{T}$

5. 装载密度（Loading density）$\lambda$ = $\frac{n}{sb}$
   
其中`b`：哈希表中桶（bucket）的数量，这里每个 `ht[i]` 对应一个桶

`s`：每个桶中槽（slot）的数量（桶的容量），从 `[0]` 到 `[s - 1]` 标识槽位

6. 冲突（Collision）：不同键映射到同一桶

7. 溢出（Overflow）：桶已满无法插入新键
   
### 哈希函数
1. 理想特性

- 最小化冲突
- 均匀分布：$Probability(f(x) = i) = 1/b$

2. 常见的哈希函数

- 整数
    - 求余法：$f(x)=x \% TableSize$
    - 折叠法
    - 平方取中
    - 分析法
- 字符串
    - 简单求和：$f(x) = (\sum x[i]) \% TableSize$（易冲突）
    - 多项式哈希：$f(x) = (x[0] + x[1]*27 + x[2]*27^2) \% TableSize$
    - 移位优化：$f(x)=(\sum x[N-i-1]*32^i) \% TableSize$（基于32的幂次，快速计算）

### 冲突解决策略
#### 分离链接法（Separate Chaining）
- 原理：每一个桶由一个链表表示

??? note "Code"
    1. **数据结构定义**
    
    ```c
    /* 链表节点结构 */
    struct ListNode {
        ElementType  Element;  // 存储的数据元素
        Position     Next;     // 指向下一个节点的指针
    };
    typedef struct ListNode *Position;  // 节点指针类型

    /* 哈希表结构 */
    struct HashTbl {
        int     TableSize;    // 哈希表大小（桶的数量）
        List    *TheLists;    // 链表头指针数组（每个元素是一个链表）
    };
    typedef struct HashTbl *HashTable;  // 哈希表指针类型
    ```

    2. **初始化哈希表**
    
    ```c
    HashTable InitializeTable(int TableSize) {
        HashTable H;
        int i;
        /* 检查表大小是否合法 */
        if (TableSize < MinTableSize) {
            Error("表大小太小");
            return NULL;
        }
        /* 分配哈希表结构体 */
        H = malloc(sizeof(struct HashTbl));
        if (H == NULL)
            FatalError("内存不足");
        /* 设置表大小为质数 */
        H->TableSize = NextPrime(TableSize);
        /* 分配链表头指针数组 */
        H->TheLists = malloc(sizeof(List) * H->TableSize);
        if (H->TheLists == NULL)
            FatalError("内存不足");
        /* 初始化每个链表的头节点（哨兵节点） */
        for (i = 0; i < H->TableSize; i++) {
            H->TheLists[i] = malloc(sizeof(struct ListNode));
            if (H->TheLists[i] == NULL)
                FatalError("内存不足");
            else
                H->TheLists[i]->Next = NULL;  // 头节点的Next初始化为空
        }
        return H;
    }
    ```

    3. **查找操作**
    
    ```c
    Position Find(ElementType Key, HashTable H) {
        Position P;
        List L;
        /* 计算哈希值确定桶位置 */
        L = H->TheLists[Hash(Key, H->TableSize)];
        /* 遍历链表查找Key（跳过头节点） */
        P = L->Next;
        while (P != NULL && P->Element != Key)  // 需根据ElementType调整比较方式
            P = P->Next;
        return P;  // 找到返回节点指针，未找到返回NULL
    }
    ```

    4. **插入操作**
    
    ```c
    void Insert(ElementType Key, HashTable H) {
        Position Pos, NewCell;
        List L;
        /* 先检查Key是否已存在 */
        Pos = Find(Key, H);
        if (Pos == NULL) {  // Key不存在时插入
            /* 创建新节点 */
            NewCell = malloc(sizeof(struct ListNode));
            if (NewCell == NULL)
                FatalError("内存不足");
            /* 将新节点插入链表头部 */
            L = H->TheLists[Hash(Key, H->TableSize)];
            NewCell->Next = L->Next;  // 新节点指向原第一个节点
            NewCell->Element = Key;   // 存储数据
            L->Next = NewCell;        // 头节点指向新节点
        }
        // 如果Key已存在，此处不做操作（可根据需求修改）
    }
    ```


#### 开放寻址法（Open Addressing）
1. **原理**：冲突时按探测序列（如线性、二次、双重哈希）寻找下一个空桶

2. **常见探测方法**

=== "**线性探测**"
    - 原理：当哈希函数计算出的初始位置已被占用时，顺序检查下一个位置，直到找到空槽或遍历整个表
    - 核心公式
        - **探测函数**：$f(i)=i$
        - **位置计算**：  
          给定初始哈希值\(h(k)\)，第\(i\)次探测的位置为$h(k, i)=(h(k)+i)\mod TableSize$
    - 线性探测的**预期探测次数** \(p\)
        -  **插入和不成功查找**：  
           
           $$
           p = \frac{1}{2} \left( 1 + \frac{1}{(1 - \lambda)^2} \right)
           $$

        -  **成功查找**：  
           
           $$
           p = \frac{1}{2} \left( 1 + \frac{1}{1 - \lambda} \right)
           $$

=== "**二次探测**"
    - 核心公式
        - **探测函数**：$f(i)=i^2$
        - **位置计算**：  
            给定初始哈希值\(h(k)\)，第\(i\)次探测的位置为$h(k, i)=(h(k)+i^2)\mod TableSize$
    - **重要定理**：
        - 如果使用二次探测，并且哈希表的大小为质数，那么当哈希表至少有一半是空的时，新元素一定可以被插入
        - **特殊情况**：如果哈希表的大小为形如$4k+3$的质数，探测函数$f(i)=\pm i^2$可探测整个表

=== "**双哈希**"
    - 原理：使用两个哈希函数，其中第一个用来计算初始哈希值
    - **探测函数**：$f(i)=i \times hash_2(x)$
    - 常用的第二个哈希函数：$hash_2(x)=R-(x\%R), 其中R是小于哈希表大小的质数$

=== "**再哈希**"
    - 触发再哈希的**时机**
        - 哈希表半满时
        - 插入操作失败时
        - 达到预设负载因子/装载密度$\lambda$时
    - **步骤**
        - 当触发再哈希之后，新建一个大小大约为原哈希表大小的两倍的哈希表
        - 遍历原哈希表中已经插入的元素
        - 使用新哈希函数重新插入到新哈希表