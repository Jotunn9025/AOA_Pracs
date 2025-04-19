def BinarySearch(arr,target)->int:
    l,r=0,len(arr)-1
    while l<=r:
        m=(l+r)//2
        if arr[m]==target:
            return m
        elif arr[m]<target:
            l=m+1
        elif arr[m]>target:
            r=m-1
    return -1

arr=[1,2,3,4,5,6,7,8,9,10]
print(BinarySearch(arr,11))