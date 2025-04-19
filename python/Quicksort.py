def Partition(arr,l,r):
    pivot=arr[l]#set first element to pivot
    i=l+1#start from left of pivot
    j=r#last element if subarray
    while True:
        while arr[i]<pivot:#move i forward till we find arr[i]>= pivot
            i+=1
        while arr[j]>pivot:#move j backwards till we find arr[j]<=pivot
            j-=1
        if i>=j:#if we have overshot and i>=j break
            break
        arr[i],arr[j]=arr[j],arr[i]#swap the pivot into position
        i+=1
        j-=1
        
    arr[l],arr[j]=arr[j],arr[l]#swap
    return j

def Quicksort(arr,l,r):
    if (l<r):#ensure no errors
        p=Partition(arr,l,r)
        Quicksort(arr,l,p-1)
        Quicksort(arr,p+1,r)

arr=[1, 0, -5, -52, -7, 21, 51, 11, 9, 54, 45, 0, -2, 4]
Quicksort(arr,0,len(arr)-1)
print(arr)