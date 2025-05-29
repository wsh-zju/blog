//O(n^2)

#include <stdio.h>

void shellsort(int *p , int n);
void insertionsort(int *p , int n,int gap);

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    shellsort(a,n);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

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