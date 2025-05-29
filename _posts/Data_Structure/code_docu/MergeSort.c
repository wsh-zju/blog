//O(n log n)

#include <stdio.h>

void mergesort(int *p , int start , int end);

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    mergesort(a,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
 
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
