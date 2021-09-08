def coutSimilarBinaryPair(arr):
    hashMap = {}
    res = 0
    for num in arr:
        cnt = 0
        while num != 0:
            num = num & (num - 1)
            cnt += 1
        if hashMap.get(cnt):
            res += hashMap[cnt]
        
        if hashMap.get(cnt) == None:
            hashMap[cnt] = 1
        else:
            hashMap[cnt] += 1
    return res