//O(n^2)

#include <stdio.h>

void bubblesort(int *p , int n);

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    bubblesort(a,n);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}


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


//another(使用递归)
/*void bubblesort(int *a, int size){
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
}*/

