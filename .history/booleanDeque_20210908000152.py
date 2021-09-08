# given an integer n, represents the length of a binary string a, initialized with 0s

# and we are also given an array called operations, it contains strings of one of the following two:
# “L” - find the first 0 starting form the left, reassign it with 1
# C{index} - set a.charAt(index)=0

# the return value should be the binary string after all the operations have been applied.

#  use bit operation to make ajustment on string
def booleanDeque(n, operations: list):
    res = 0
    for operation in operations:
        if operation[0] == "L":
            k = n
            while k > 0:
                cur = res >> (k - 1) & 1        # check if kth digit is 1
                if cur == 1:                    # kth digit is 1
                    k -= 1
                else:                           # kth digit is 0
                    res = res | (1 << (k - 1))
                    break
        else:
            digit = int(operation[1])
            res = res & (~(1 << (n - digit - 1)))
            
    return bin(res).replace('0b','')

print(booleanDeque(4, ["L", "L", "C1", "L"]))