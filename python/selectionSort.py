def SelectionSort(arr):
    n=len(arr)
    sorted_index=0  #keeps track of where to place lowest index
    for i in range(n-1):
        selected_value=float('inf')#initialize to infinity so we always find a smaller val
        swap_index=sorted_index
        for j in range(sorted_index+1,n):
            if selected_value>arr[j]:#find minimum and update index
                selected_value=arr[j]
                swap_index=j
        arr[sorted_index],arr[swap_index]=arr[swap_index],arr[sorted_index]#swap
        sorted_index+=1#increment

arr=[10,54,12,53,91,0,-2,5,2,7,12,55,91,91,43,71]#testcase
SelectionSort(arr)
print(arr)
            
    