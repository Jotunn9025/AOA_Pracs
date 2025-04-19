def InsertionSort(arr):
    n=len(arr)
    sorted_index=0#say that subarray from 0 to 0 is sorted
    for i in range (1,n):
        element=arr[sorted_index+1]#choose first element from unsorted array
        j=sorted_index#pointer to last element of sorted array
        while element<arr[j] and j>=0:#while element is smaller than sorted swap it downwards till in right place
            arr[j+1]=arr[j]
            arr[j]=element
            j-=1
        sorted_index+=1#swap next element

arr=[10,54,12,53,91,0,-2,5,2,7,12,55,19,21,43,71]#testcase
InsertionSort(arr)
print(arr)
            