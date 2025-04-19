#include <stdio.h>
int binarysearch(int arr[],int l,int r,int target){//basic binary seacrch
     while (l<=r){
        int m=(l+r)/2;
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
    int arr[10]={1,2,3,4,6,7,8,9,11};
    printf("\n%d\n",binarysearch(arr,0,8,9));
    return 0;
}