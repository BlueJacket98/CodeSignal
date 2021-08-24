import sys

def deleteMinimalPeaks(nums):
    res = []
    while nums:
        minPeak = sys.maxsize
        if len(nums) == 1:
            tmp = nums.pop()
            res.append(tmp)
            continue

        if nums[0] > nums[1]:
            minPeak = min(minPeak, nums[0])

        if nums[len(nums) - 2] < nums[len(nums) - 1]:
            minPeak = min(minPeak, nums[len(nums) - 1])

        if len(nums) >= 3:
            for i in range(1, len(nums) - 1):
                if nums[i-1] < nums[i] and nums[i] > nums[i+1]:
                    minPeak = min(minPeak, nums[i])

        minPeakIdx = nums.index(minPeak)
        tmp = nums.pop(minPeakIdx)
        res.append(tmp)
    return res

print(deleteMinimalPeaks([1,9,7,8,2,6]))
print(deleteMinimalPeaks([1,4,5,3,8,6]))