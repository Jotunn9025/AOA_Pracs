#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void swap(int*a,int*b){
    int temp=*a;*a=*b;*b=temp;
}
void SelectionSort(int n,int arr[]){
    int sortedIndex=0;
    for (int i=0;i<n-1;i++,sortedIndex++){
        int min=INT_MAX;
        int mindex=sortedIndex;
        for (int j=sortedIndex;j<n;j++){
            if(arr[j]<min){
                min=arr[j];
                mindex=j;
            }
        }
        swap(&arr[mindex],&arr[sortedIndex]);
    }
}
int main(){
    int arr[10]={9,8,7,0,5,3,2,1,4,6};
    SelectionSort(10,arr);
    for(int i=0;i<10;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}