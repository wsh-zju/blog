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

/*void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[low];
        int i = low - 1;
        int j = high + 1;
        while (1) {
            do {
                i++;
            } while (arr[i] < pivot);
            do {
                j--;
            } while (arr[j] > pivot);
            if (i >= j) {
                break;
            }
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        quicksort(arr, low, j);
        quicksort(arr, j + 1, high);
    }
}*/

void quicksort(int *p , int start ,int end){
    if(start<end){
        int temp=*(p+start);
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