#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int Partition(int arr[],int l, int r){
    int val=arr[l];
    int i=l+1,j=r;
    while(i<=j){
        while(arr[i]<val)
            i++;
        while(arr[j]>val)
            j--;
        if(i>=j)
            break;
        swap(&arr[i],&arr[j]);
    }
    swap(&arr[l],&arr[j]);
    return j;
}

void qs(int arr[],int l,int r){
    if(l<r){
        int pivt=Partition(arr,l,r);
        qs(arr,l,pivt-1);
        qs(arr,pivt+1,r);
    }
}
int main(){
    int arr[11]={9,8,7,0,5,3,2,1,2,6,-2};
    qs(arr,0,10);
    for(int i=0;i<11;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}