# LeetCode 1861. Rotating the Box

class Solution:
    def rotateTheBox(self, box: List[List[str]]) -> List[List[str]]:
        m = len(box)
        n = len(box[0])
        # record the j index of the rightmost obs on that row
        rightmostObs = [n for _ in range(m)]
        for j in range(n - 1, -1, -1):
            for i in range(m):
                if box[i][j] == ".":
                    pass
                elif box[i][j] == "*":
                    rightmostObs[i] = j
                elif box[i][j] == "#":
                    newColIdx = rightmostObs[i] - 1
                    if newColIdx != j:
                        box[i][j] = "."
                        box[i][newColIdx] = "#"
                    rightmostObs[i] = newColIdx

        res = [["" for _ in range(m)] for _ in range(n)]
        for i in range(m):
            for j in range(n):
                res[j][m - i - 1] = box[i][j]
        
        return res