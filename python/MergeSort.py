def Merge(arr1,arr2):#merge 2 arrays according to length
    i,j=0,0
    res=[]
    while i <len(arr1) and j<len(arr2):
        if arr1[i]<arr2[j]:
            res.append(arr1[i])
            i+=1
        else:
            res.append(arr2[j])
            j+=1
    if i<len(arr1):
        res.extend(arr1[i:])
    elif j<len(arr2):
        res.extend(arr2[j:])
    return res
def MergeSort(arr):#recursive mergesort
    if len(arr)<=1:
        return arr
    mid=len(arr)//2
    left=MergeSort(arr[:mid])
    right=MergeSort(arr[mid:])
    return Merge(left,right)

arr=[1,0,3,2,2,2,56,12]
arr=MergeSort(arr)#have to overwrite as this implementation is not in place(Honestly not worth it to do inplace its more complex)
print(arr)