# 建立一个栈

def removingPairsGame(nums):
    stack = []
    cnt = 0
    for i in range(len(nums)):
        if not stack:
            stack.append(nums[i])
        elif stack and stack[-1] != nums[i]:
            stack.append(nums[i])
        else:
            stack.pop()
            cnt += 1
    
    if cnt % 2 == 1:
        return "Alice"      # whoever starts first
    else:
        return "Bob"