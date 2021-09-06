# LeetCode 1329

class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        self.mat = mat
        m = len(self.mat)
        n = len(self.mat[0])
        for i in range(m):
            self.sortDiagnal(i, 0)
        for j in range(1, n):
            self.sortDiagnal(0, j)
        return self.mat

    def sortDiagnal(self, i, j):
        m = len(self.mat)
        n = len(self.mat[0])
        path = []
        value = []
        while 0 <= i <= m - 1 and 0 <= j <= n - 1:
            path.append((i, j))
            value.append(self.mat[i][j])
            i += 1
            j += 1
        value.sort()
        for i in range(len(path)):
            self.mat[path[i][0]][path[i][1]] = value[i]