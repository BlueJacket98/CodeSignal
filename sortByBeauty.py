import copy

def sortByBeauty(numbers, size):
    submatrices = []
    m = len(numbers)
    n = len(numbers[0])
    for i in range(0, m, size):
        for j in range(0, n, size):
            submatrice = []
            for x in range(size):
                submatrice += numbers[i+x][j:j+size]
            submatrices.append(submatrice)
    submatrices.sort(key=lambda x:firstMissingPositive(x))
    cnt = 0
    for i in range(0, m, size):
        for j in range(0, n, size):
            for x in range(size):
                for y in range(size):
                    numbers[i+x][j+y] = submatrices[cnt].pop(0)
            cnt += 1
    return numbers

def firstMissingPositive(submatrice):
    nums = copy.deepcopy(submatrice)
    n = len(nums)
    for i in range(n):
        if nums[i] <= 0:
            nums[i] = n + 1
    
    for i in range(n):
        num = abs(nums[i])
        if num <= n:
            nums[num - 1] = -abs(nums[num - 1])
    
    for i in range(n):
        if nums[i] > 0:
            return i + 1
    
    return n + 1

print(sortByBeauty([[1, 2,  2,  3],
                    [3, 4,  10, 4],
                    [2, 10, 1,  2],
                    [5, 4,  4,  5]], 2))