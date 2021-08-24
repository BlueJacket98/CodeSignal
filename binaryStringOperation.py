import copy
def binaryStringOperation(s: str, ops: list):
    num = int(s, 2)
    res = []
    for op in ops:
        if op == "+":
            num += 1
        elif op == "?":
            numCopy = copy.deepcopy(num)
            cnt = 0
            while numCopy != 0:
                numCopy = numCopy & (numCopy - 1)
                cnt += 1
            res.append(cnt)
    return res

s = "1101"
ops = ["+", "?", "+", "?", "+", "?"]
print(binaryStringOperation(s, ops))