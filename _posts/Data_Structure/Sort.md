## 简单排序
### 选择排序 [Selection Sort.c](code_docu/SelectionSort.c)
```c
void selectionsort(int *p , int n){
    int min;
    int index;
    for(int j=0;j<n;j++){
        min=*(p+j);
        index=j;
        for(int i=j;i<n;i++){
            if(*(p+i)<min){
                min=*(p+i);
                index=i;
            }
        }
        *(p+index)=*(p+j);
        *(p+j)=min;
    }
}
```

### 冒泡排序 [Bubble Sort.c](code_docu/BubbleSort.c)
- 方法一：
    ```c
    void bubblesort(int *p , int n){
        int i,j;
        for(i=n-1;i>0;i--){
            for(j=0;j<i;j++){
                if(*(p+j)>*(p+j+1)){
                    int temp=*(p+j);
                    *(p+j)=*(p+j+1);
                    *(p+j+1)=temp;  
                    n=j+1;  //记录最后一次交换的位置
                }
            }
        }
    }
    ```

- 方法二：递归
    ```c
    void bubblesort(int *a, int size){
        if ( size>1 ) {
            for ( int j=0; j<size-1; j++ ) {
                if ( a[j] > a[j+1] ) {
                    int t = a[j];                
                    a[j] = a[j+1];                
                    a[j+1] = t;            
                }         
            }
            bubblesort(a, size-1);    
        } 
    }
    ```

### 插入排序 [Insert Sort.c](code_docu/InsertionSort.c)
- 方法一：
    ```c
    void insertionsort(int *p , int n){
        if(n>1){
            insertionsort(p,n-1);
            int index=n-1;
            int temp=*(p+n-1);
            for(int i=0;i<n-1;i++){
                if(*(p+i)>*(p+index)){
                    index=i;
                    break;
                }
            }
            for(int j=n-1;j>index;j--){
                *(p+j)=*(p+j-1);
            }
            *(p+index)=temp;
        }
    }
    ```

- 方法二：倒序
    ```c
    void insertionsort(int *p , int n){
        if(n>1){
            insertionsort(p,n-1);
            int index=n-1;
            int temp=*(p+n-1);
            for(int i=n-1;i>0 && *(p+i-1)>temp;i--){
                *(p+i)=*(p+i-1);
                index=i-1;
            }
            *(p+index)=temp;
        }
    }
    ```

## 高级排序
### 希尔排序 [Shell's Sort.c](code_docu/ShellSort.c)
- 时间复杂度：（与选择的增量序列有关）
    - 朴素增量序列（ $N/2,N/4,...,1$ ）
        - 最坏时间复杂度： $O(N^2)$
        - 最好时间复杂度： $O(N\log N)$
        - 平均时间复杂度： $O(N^{\frac{3}{2}})$
    - Hibbard增量序列（ $h_k=2^k-1$ ）
        - 最坏时间复杂度： $O(N^{\frac{3}{2}})$
        - 最好时间复杂度： $O(N\log N)$
        - 平均时间复杂度： $O(N^{\frac{5}{4}})$
    - Sedgewick增量序列（ $1,5,19,41,109,...$ ）
        - 最坏时间复杂度： $O(N^{\frac{4}{3}})$
        - 最好时间复杂度： $O(N\log N)$
        - 平均时间复杂度： $O(N^{\frac{7}{6}})$

```c
void shellsort(int *p , int n){
    int gap=n/2;
    while(gap>0){
        for(int i=0;i<gap;i++){
            insertionsort(p+i,n-i,gap);
        }
        for(int i=0;i<n;i++){
            printf("%d ",*(p+i));
        }
        printf("\n");
        gap/=2;
    }
}

void insertionsort(int *p , int n,int gap){
    if(n>gap){
        insertionsort(p,n-gap,gap);
        int index=n-1;
        int temp=*(p+n-1);
        for(int i=n-1;i>0 && *(p+i-gap)>temp;i=i-gap){
            *(p+i)=*(p+i-gap);
            index=i-gap;
        }
        *(p+index)=temp;
    }
}
```

### 归并排序 [Merge Sort.c](code_docu/MergeSort.c)
- 时间复杂度： $O(N\log N)$

```c
void mergesort(int *p , int start , int end){
    if(start<end){
        int mid=(start+end)/2;
        mergesort(p,start,mid);
        mergesort(p,mid+1,end);
        int i=start,j=mid+1;
        int k=start;
        int b[end+1];
        while(i<mid+1 && j<end+1){
            if(*(p+i)<*(p+j)){
                b[k++]=*(p+i);
                i++;
            }else{
                b[k++]=*(p+j);
                j++;
            }
        }
        for(;i<mid+1;i++){
            b[k++]=*(p+i);
        }
        for(;j<end+1;j++){
            b[k++]=*(p+j);
        }
        for(int s=start;s<end+1;s++){
            *(p+s)=b[s];
        }
    }
}
```


### 快速排序 
- 时间复杂度
    - 最坏情况 $O(N^2)$
    - 最好情况 $O(N\log N)$
    - 平均情况 $O(N\log N)$
- Hoare分区 [Hoare QuickSort.c](code_docu/HoareQuickSort.c)
    - 思路：左右两个指针，左边找比temp大的元素，右边找比temp小的元素，交换
    
    ```c
    void quicksort(int *p , int start ,int end){
        if(start<end){
            int temp=*(p+start);  //分区元素为开头元素
            int i=start+1;
            int j=end;
            do{
                while(*(p+i)<temp&&i<end){
                    i++;
                }
                while(*(p+j)>temp&&j>start){
                    j--;
                }
                if(i<j){
                    int a=*(p+i);
                    *(p+i)=*(p+j);
                    *(p+j)=a;
                    i++;
                    j--;
                }
            }while(i<j);
            *(p+start)=*(p+j);
            *(p+j)=temp;
            quicksort(p,start,j-1);
            quicksort(p,j+1,end);
        }
    }
    ```

- Lomuto分区 [Lomuto QuickSort.c](code_docu/LomutoQuickSort.c)
    
    ```c
    void quicksort(int *p , int start ,int end){
        if(start<end){
            int temp=*(p+end);   //分区元素为最后一个元素
            int i=end-1;
            for(int k=end-1;k>start-1;k--){
                if(*(p+k)>temp){
                    int a=*(p+i);
                    *(p+i)=*(p+k);
                    *(p+k)=a;
                    i--;
                }
            }
            *(p+end)=*(p+i+1);
            *(p+i+1)=temp;
            quicksort(p,start,i);
            quicksort(p,i+2,end);
        }
    }
    ```

!!! note "Notice!"
    也可以从开头、结尾和中间的三个元素中选择一个中等的

### 堆排序（heap sort）
- 思路：利用最大/最小堆
- 平均时间复杂度： $O(N\log N)$
- 对于包含 \( N \) 个不同元素的随机排列，堆排序的平均比较次数为：  
    \[ 
    2N \log N - O(N \log \log N) 
    \]  
- 方法一：
    ```c
    void heapsort(ElementType H[],int N){
        BuildHeap(H);  //O(N)
        for(int i=0;i<N;i++) 
            TmpH[i]=DeleteMin(H);  //O(log N)
        for(int i=0;i<N;i++) 
            H[i]=TmpH[i];  //需要赋值给原来的数组
    }
    ```

- 方法二：
    ```c
    void Heapsort(ElementType A[],int N){   //不需要赋值给原来的数组
        int i; 
        for(i=N/2;i>=0;i--) /* BuildMaxHeap */ 
            PercDown(A,i,N); 
        for(i=N-1;i>0;i--){ 
            Swap(&A[0],&A[i]); /* DeleteMax */ 
            PercDown(A,0,i); 
        }
    } 
    ```
    
    !!! note "Notice!"
        第二个方法中，根节点的序号为0，不满足 $2i$ 和 $2i+1$ 的关系
 
### 桶排序（bucket sort）
基数排序的基础
### 基数排序（radix sort）
- 思路：按照个十百千……的顺序进行比较；在之前排序的基础上进行之后的排序
- 时间复杂度： $O(dN)$ (d是数据最多的位数)
- 分类：
    -  Least Signification Digit (LSD)：最小位优先
    -  Most Significant Digit(MSD)：最大位优先
