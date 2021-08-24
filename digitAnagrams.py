def digitAnagrams(a):
    hashMap = {}
    for i in range(len(a)):
        num = a[i]
        mask = [0 for _ in range(10)]
        for char in str(num):
            mask[int(char)] += 1
        tupleMask = tuple(mask)
        if hashMap.get(tupleMask) == None:
            hashMap[tupleMask] = 1
        else:
            hashMap[tupleMask] += 1

    cnt = 0
    print(hashMap)
    for key, value in hashMap.items():
        if value >= 2:
            cnt += sum(range(1, value))
    return cnt

print(digitAnagrams([25,35,872,228,53,278,872]))
