# 一个array，问你0<i<j<len(array),有多少对arrary[i],arrary[j] such that 它们的binary是有一样数目的1。这个需要o(n)才能通过所有‍‌‌‌‌‌‌‌‍‍‌‍‌‍‍‌‌‍‌‌test case

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