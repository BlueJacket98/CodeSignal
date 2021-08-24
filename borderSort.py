def borderSort(mat):
    if mat == None or mat == []:
        return []

    m = len(mat)
    n = len(mat[0])
    # 维护现在可以接触到的四边
    left = 0
    right = n - 1
    top = 0
    bottom = m - 1
    
    numEle = m * n

    while numEle >= 1:
        path = []
        elems = []
        if numEle >= 1:
            for i in range(left, right + 1):
                path.append([top, i])
                elems.append(mat[top][i])
                numEle -= 1
            top += 1
        
        if numEle >= 1:
            for i in range(top, bottom + 1):
                path.append([i, right])
                elems.append(mat[i][right])
                numEle -= 1
            right -= 1

        if numEle >= 1:
            for i in range(right, left - 1, -1):
                path.append([bottom, i])
                elems.append(mat[bottom][i])
                numEle -= 1
            bottom -= 1

        if numEle >= 1:
            for i in range(bottom, top - 1, -1):
                path.append([i, left])
                elems.append(mat[i][left])
                numEle -= 1
            left += 1

        elems.sort()
        for i in range(len(path)):
            idx = path[i]
            mat[idx[0]][idx[1]] = elems[i]

    return mat


mat = [[0, 4, 2, 6],
    [7, 3, 5, 8],
    [2, 2, 1, 1],
    [4, 9, 0, -1]]
print(borderSort(mat))