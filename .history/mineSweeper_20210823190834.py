class Solution:
    def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
        self.board = board
        self.m = len(board)
        self.n = len(board[0])
        self.clickOnce(self.board, click)
        
        return self.board

    def clickOnce(self, board, click):
        i = click[0]
        j = click[1]
        if self.board[i][j] == "M":
            self.board[i][j] = "X"
        elif self.board[i][j] == "E":
            adjacentMines = []
            for coordinate in self.getAdjacentCoordinates(i, j):
                if 0 <= coordinate[0] <= self.m - 1 and 0 <= coordinate[1] <= self.n - 1:
                    if board[coordinate[0]][coordinate[1]] == "M":
                        adjacentMines.append(coordinate)
            if adjacentMines == []:
                self.board[i][j] = "B"
                for coordinate in self.getAdjacentCoordinates(i, j):
                    if 0 <= coordinate[0] <= self.m - 1 and 0 <= coordinate[1] <= self.n - 1:
                        self.clickOnce(self.board, coordinate)
            else:
                self.board[i][j] = str(len(adjacentMines))
        
    def getAdjacentCoordinates(self, i, j):
        return [[i-1,j-1],[i-1,j],[i-1,j+1],[i,j-1],[i,j+1],[i+1,j-1],[i+1,j],[i+1,j+1]]