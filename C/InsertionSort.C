#include <stdio.h>
void swap(int *a, int* b){
    int temp=*a;*a=*b;*b=temp;
}
void InsertionSort(int arr[],int n){
    for (int i=1;i<n;i++){
        int j=i-1;
        int val=arr[i];
        while(j>=0&& arr[j]>val){
            swap(&arr[j],&arr[j+1]);
            arr[j]=val;;
            j--;
        }
    }
}
int main(){
    int arr[11]={9,8,7,0,5,3,2,1,2,6,-2};
    InsertionSort(arr,11);
    for(int i=0;i<11;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}