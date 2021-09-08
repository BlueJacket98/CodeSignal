def isCyclicArray(arr):
    arrSorted = sorted(arr)
    arr = arr + arr
    print(arr)
    return arrSorted in arr

print(isCyclicArray([3,4,1,2]))
print(isCyclicArray([4,3,1,2]))