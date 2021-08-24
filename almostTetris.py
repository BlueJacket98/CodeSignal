class Solution:
    def almostTetris(self, n, m, figures):
        # n row, m col
        self.sheet = [[0 for _ in range(m)] for _ in range(n)]
        self.n = n
        self.m = m
        for idx in range(len(figures)):
            figure = figures[idx]
            exitFlag = False
            for i in range(n):
                for j in range(m):
                    if not exitFlag and self.isValidLocation(i, j, figure, idx+1):
                        exitFlag = True
        return self.sheet

    def isValidLocation(self, i, j, figure, idx):
        if figure == 1:
            if self.isZero(i, j):
                self.sheet[i][j] = idx
                return True
            else:
                return False
        elif figure == 2:
            if self.isZero(i, j) and self.isZero(i, j+1) and self.isZero(i, j+2):
                self.sheet[i][j] = idx
                self.sheet[i][j+1] = idx
                self.sheet[i][j+2] = idx
                return True
            else:
                return False
        elif figure == 3:
            if self.isZero(i, j) and self.isZero(i, j+1) and self.isZero(i+1, j) and self.isZero(i+1, j+1):
                self.sheet[i][j] = idx
                self.sheet[i][j+1] = idx
                self.sheet[i+1][j] = idx
                self.sheet[i+1][j+1] = idx
                return True
            else:
                return False
        elif figure == 4:
            if self.isZero(i, j) and self.isZero(i+1, j) and self.isZero(i+1, j+1) and self.isZero(i+2, j):
                self.sheet[i][j] = idx
                self.sheet[i+1][j] = idx
                self.sheet[i+1][j+1] = idx
                self.sheet[i+2][j] = idx
                return True
            else:
                return False
        elif figure == 5:
            if self.isZero(i, j) and self.isZero(i+1, j-1) and self.isZero(i+1, j) and self.isZero(i+1, j+1):
                self.sheet[i][j] = idx
                self.sheet[i+1][j-1] = idx
                self.sheet[i+1][j] = idx
                self.sheet[i+1][j+1] = idx
                return True
            else:
                return False
    
    def isZero(self, i, j):
        if 0 <= i <= self.n - 1 and 0 <= j <= self.m - 1 and self.sheet[i][j] == 0:
            return True
        else:
            return False

a = Solution()
print(a.almostTetris(4, 4, [4,2,1,3]))
