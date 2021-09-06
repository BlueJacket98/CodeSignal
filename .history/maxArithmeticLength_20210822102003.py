def maxArithmeticLength(a: list, b: list) -> int:
    nums = a + b
    nums.sort()
    n = len(nums)
    # (endIdx, step) -> maxLen
    hashMap = {}
    res = 0
    for i in range(1, n):
        for j in range(0, i):
            step = nums[i] - nums[j]
            if hashMap.get((j, step)) == None:
                hashMap[(i, step)] = 2
            else:
                hashMap[(i, step)] = hashMap[(j, step)] + 1

            res = max(res, hashMap[(i, step)])
    return res


inputA = [2, 4, 8]
inputB = [1, 6, 10, 12]
print(maxArithmeticLength(inputA, inputB))