# bouncingDiagonals
# movingDiagonally
def matrixBounce(mat):
    elemSum = []    #List[List[]]
    n = len(mat)
    for i in range(n):
        elemSum.append([mat[i][0], traverse(mat, i, 0)])
    elemSum.sort(key=lambda x:x[1])
    res = []
    for elem in elemSum:
        res.append(elem[0])
    return res

# 一定要注意细节，在写的时候就仔仔细细想好，不然最后调不出来
def traverse(mat, startI, startJ):
    n = len(mat)
    curSum = 0
    i, j = startI, startJ
    while 0 <= i <= n - 1 and 0 <= j <= n - 1:
        curSum += mat[i][j]
        i -= 1
        j += 1
    i += 2
    j += 0
    while 0 <= i <= n - 1 and 0 <= j <= n - 1:
        curSum += mat[i][j]
        i += 1
        j += 1
    return curSum

mat = [[10,13,14,21,23],
       [11,9,22,2,3],
       [12,8,1,5,4],
       [15,24,7,6,20],
       [16,17,18,19,25]]
print(matrixBounce(mat))