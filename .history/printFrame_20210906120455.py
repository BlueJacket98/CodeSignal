def printFrame(n):
    res = []
    if n == 1:
        res.append("*" * n)
        return res
    elif n == 2:
        res.append("*" * n)
        res.append("*" * n)
        return res
    for i in range(n):
        if i == 1:
            res.append("*" * n)
        elif i == n - 1:
            res.append("*" * n)
        else:
            res.append("*" + " " * (n - 2) + "*")

    return res

print(printFrame(3))