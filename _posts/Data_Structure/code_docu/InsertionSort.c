//O(n^2)

#include <stdio.h>

void insertionsort(int *p , int n);

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    insertionsort(a,n);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}


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


//another(倒序)
/*void insertionsort(int *p , int n){
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
}*/