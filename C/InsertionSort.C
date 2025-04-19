#include <stdio.h>
void swap(int*a,int*b){
    int temp=*a;*a=*b;*b=temp;
}
void InsertionSort(int arr[],int n){
    for(int k=1;k<n;k++){
        int element=arr[k];
        int j=k-1;
        while (element<arr[j] && j>=0){//keep swapping till in right place
            swap(&arr[j],&arr[j+1]);
            j--;
        }
    }
}
int main(){
    int arr[10]={5,3,2,-1,0,-25,-65,65,100,43};
    InsertionSort(arr,10);
    for (int i = 0; i < 10; i++)
        printf("%d\t",arr[i]);
    return 0;
}