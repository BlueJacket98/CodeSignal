# LeetCode 452

class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key=lambda x:x[0])
        # leftmost right bound
        curRightBound = points[0][1]
        curStart = points[0][0]
        cnt = 0
        for i in range(1, len(points)):
            curBal = points[i]
            if curBal[0] <= curRightBound:
                curRightBound = min(curRightBound, curBal[1])
            else:
                curStart = curBal[0]
                curRightBound = curBal[1]
                cnt += 1
        return cnt + 1