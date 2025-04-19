#include <stdio.h>
void swap(int* a, int* b){//swap func
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[100],int l,int r){
    int i,j,pivot;
    j = l-1;
    pivot = arr[r];
    for (i = l; i < r ; i++){
        if (arr[i]<pivot){//swap all smaller elements with j (2pointer approach to swapping but not from opp ends like in python)
            j+=1;
            swap(&arr[j], &arr[i]);
        }
    }
    swap(&arr[j+1], &arr[r]);
    return j+1;//retrun index
}
void quicksort(int arr[100],int l,int r){
    int pivt;
    if (l<r){
        pivt=partition(arr,l,r);
        quicksort(arr,l,pivt-1);
        quicksort(arr,pivt+1,r);
    }
}
int main(){
    int i,n,arr[100],l,r;
    printf("enter number of elements\n");
    scanf("%d",&n);
    printf("\nenter elements\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    l=0;
    r=n-1;
    quicksort(arr,l,r);
    printf("\n\nSORTED:\n");
    for(i=0;i<n;i++){
        printf("%6d",arr[i]);
}
return 0;
}