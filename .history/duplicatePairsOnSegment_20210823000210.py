def duplicatePairsOnSegment(numbers, k):
    n = len(numbers)
    i, j = 0, 0
    cnt = 0
    hashMap = {numbers[0]: 1}
    while i < n:
        while not isValidSubarray(hashMap, k):
            i += 1
            if i >= n:
                return cnt
            if hashMap.get(numbers[i]) == None:
                hashMap[numbers[i]] = 1
            else:
                hashMap[numbers[i]] += 1
        if isValidSubarray(hashMap, k):
            cnt += n - i

        j += 1
        hashMap[numbers[j-1]] -= 1
    return cnt

def isValidSubarray(hashMap: dict, k: int):
    cnt = 0
    for key, value in hashMap.items():
        if value >= 2:
            cnt += value // 2
            if cnt >= k:
                return True
    return False

print(duplicatePairsOnSegment([0,1,0,1,0], 2))
print(duplicatePairsOnSegment([2,2,2,2,2,2], 3))
print(duplicatePairsOnSegment([1,3,3,1], 1))