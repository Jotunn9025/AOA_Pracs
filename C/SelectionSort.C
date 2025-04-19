#include <stdio.h>
void swap(int*a,int*b){
    int temp=*a;*a=*b;*b=temp;
}
void SelectionSort(int arr[],int n){
    int sorted_index=0;
    
    int mindex;
    for(int k=0;k<n-1;k++){
        int min=0x7FFFFFFF;//largest int in hex
        mindex=sorted_index;//set mindex to end of sorteed region
        for (int i=sorted_index;i<n;i++){//find smallest
            if (arr[i]<min){
                min=arr[i];
                mindex=i;
            }
        }
        swap(&arr[sorted_index],&arr[mindex]);//swap smallest with end of sortedregion
        sorted_index++;
    }
}
int main(){
    int arr[10]={5,3,2,-1,0,-25,-65,65,100,43};
    SelectionSort(arr,10);
    for (int i = 0; i < 10; i++)
        printf("%d\t",arr[i]);
    return 0;
}