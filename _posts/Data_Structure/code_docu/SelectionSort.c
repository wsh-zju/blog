//O(n^2)

#include <stdio.h>

void selectionsort(int *p , int n);

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    selectionsort(a,n);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}

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

