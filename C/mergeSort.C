#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void Merge(int arr[],int l,int m,int r){
    int n1=m-l+1;
    int n2=r-m;
    int* left=(int*)malloc(sizeof(int)*n1);
    int* right=(int*)malloc(sizeof(int)*n2);
    for(int i=0;i<n1;i++)
        left[i]=arr[l+i];
    for(int i=0;i<n2;i++)
        right[i]=arr[m+1+i];
    int i=0,j=0,k=l;
    while(i<n1&& j<n2){
        if (left[i]<right[j])
            arr[k++]=left[i++];
        else
            arr[k++]=right[j++];
    }
    if (i==n1)
        while(j<n2)
            arr[k++]=right[j++];
    else if (j==n2)
        while(i<n1)
            arr[k++]=left[i++];
}

void MergeSort(int arr[],int l,int r){
    if(l<r){
        int m=(l+r)/2;
        MergeSort(arr,l,m);
        MergeSort(arr,m+1,r);
        Merge(arr,l,m,r);
    }
}
int main(){
    int arr[11]={9,8,7,0,5,3,2,1,2,6,-2};
    MergeSort(arr,0,10);
    for(int i=0;i<11;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}