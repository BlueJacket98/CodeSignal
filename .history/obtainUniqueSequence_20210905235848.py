# 945. Minimum Increment to Make Array Unique
class Solution:
    def obtainUniqueSequence(self, nums: List[int]) -> int:
        nums.sort()
        cnt = 0
        for i in range(1, len(nums)):
            if nums[i] <= nums[i-1]:
                incre = nums[i-1] + 1 - nums[i]
                nums[i] += incre
                cnt += incre
        return cnt

a = Solution()
print(a.obtainUniqueSequence([5, 1, 2, 4, 5, 2]))