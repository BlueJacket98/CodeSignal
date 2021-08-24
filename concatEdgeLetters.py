def concatEdgeLetters(a):
    res = ["" for _ in range(len(a))]
    for i in range(len(a)):
        if i == len(a) - 1:
            res[i] = a[i][0] + a[0][-1]
        else:
            res[i] = a[i][0] + a[i+1][-1]
    return res

print(concatEdgeLetters(["cat", "dog", "ferret", "scorpion"]))