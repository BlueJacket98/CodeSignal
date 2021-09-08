def sortByMissingNum(mat):
    # mat: [List[List[List[int]]]]
    mat.sort(key=lambda x:findMissingNum(x))
    return mat
        

def findMissingNum(matrix):
    FIXED_SUM = (1 + 16) * 16 / 2
    questionMark = (None, None)
    curSum = 0
    for i in range(4):
        for j in range(4):
            if matrix[i][j] == "?":
                questionMark = (i, j)
            curSum += int(matrix[i][j])
    missingNum = FIXED_SUM - curSum
    matrix[questionMark[0]][questionMark[1]] = str(missingNum)
    return missingNum