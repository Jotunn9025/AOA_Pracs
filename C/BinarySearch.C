#include <stdio.h>
int binarySearch(int arr[],int n,int target){
    int l=0,r=n-1;
    while(l<=r){
        int m=(r+l)/2;
        if (arr[m]==target)
            return m;
        else if (arr[m]<target)
            l=m+1;
        else
            r=m-1;
    }
    return -1;
}

int main(){
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    printf("%d",binarySearch(arr,10,11));
    return 0;
}