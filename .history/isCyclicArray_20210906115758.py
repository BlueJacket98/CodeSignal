def isCyclicArray(arr):
    arrSorted = sorted(arr)
    arr = arr + arr
    print(arr)
    return isSubarray(arrSorted, arr)

def isSubarray(subarr, arr):
    i= 0
    for i in range(len(arr) - len(subarr)):
        if arr[i:i+len(subarr)] != subarr:
            continue
        else:
            return True
    return False
        

print(isCyclicArray([3,4,1,2]))
print(isCyclicArray([4,3,1,2]))