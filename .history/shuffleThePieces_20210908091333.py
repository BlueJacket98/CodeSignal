def shuffleThePieces(arr, pieces):
    hashMap = {}
    for piece in pieces:
        firstNum = piece[0]
        if hashMap.get(firstNum) == None:
            hashMap[firstNum] = [piece]
        else:
            hashMap[firstNum].append(piece)
    global cnt
    cnt = 0
    def dfs(combine, remain):
        global cnt
        if remain == []:
            if combine == arr:
                cnt += 1
            return
        requiredNum = remain[0]
        if hashMap.get(requiredNum) == None:
            return
        else:
            candidates = hashMap[requiredNum]
        for i in range(len(candidates)):
            candidate = candidates[i]
            if len(candidate) > len(remain) or candidate != remain[:len(candidate)]:
                continue
            else:
                hashMap[requiredNum].pop(i)
                dfs(combine + candidate, remain[len(candidate):])
                hashMap[requiredNum].insert(i, candidate)
    
    dfs([], arr)
    if cnt == 0:
        return False
    else:
        return True
