# https://oss.1point3acres.cn/forum/202012/14/074659sw7lb1wuubbk1uwu.png
import numpy as np

def diagonalsArranging(a):
    n = len(a)
    diagList = []
    diagIdx = {}
    res = []

    for idx in range(n - 1, -1, -1):
        i = idx
        j = 0
        curDiag = ""
        while i < n and j < n:
            curDiag += a[i][j]
            i += 1
            j += 1
        if len(curDiag) < n:
            curDiag = fillString(curDiag, n)
        diagList.append(curDiag)
        diagIdx[curDiag] = idx
    
    for idx in range(1, n):
        i = 0
        j = idx
        curDiag = ""
        while i < n and j < n:
            curDiag += a[i][j]
            i += 1
            j += 1
        if len(curDiag) < n:
            curDiag = fillString(curDiag, n)
        diagList.append(curDiag)
        diagIdx[curDiag] = idx + n

    return np.argsort(diagList) + 1

def fillString(s, n):
    curLen = len(s)
    times = n // curLen
    remainder = n % curLen
    s += (times - 1) * s
    s += s[:remainder]
    return s

a = [["a","c","a","b","b"],
["c","b","a","c","b"],
["a","a","e","c","b"],
["b","b","d","a","g"],
["a","b","e","b","a"]]
print(diagonalsArranging(a))