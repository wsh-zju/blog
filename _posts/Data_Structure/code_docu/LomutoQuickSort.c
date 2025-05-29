//O(n log n)-O(n^2)

#include <stdio.h>

void quicksort(int *p , int start ,int end);

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

void quicksort(int *p , int start ,int end){
    if(start<end){
        int temp=*(p+end);
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
