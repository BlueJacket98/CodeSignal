def digitsManipulation(n: int) -> int:
    nStr = str(n)
    curSum = 0
    curPro = 1
    for ch in nStr:
        curSum += int(ch)
        curPro *= int(ch)
    return curPro - curSum

print(digitsManipulation(123456))
print(digitsManipulation(1010))