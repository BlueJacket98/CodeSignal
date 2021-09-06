# LeetCode 1047

class Solution:
    def removeDuplicates(self, s: str) -> str:
        stack = []
        for i in range(len(s)):
            if not stack or (stack and s[i] != stack[-1]) :
                stack.append(s[i])
            else:
                stack.pop(-1)
            
            while len(stack) >= 2 and stack[-1] == stack[-2]:
                stack.pop(-1)
                stack.pop(-2)
        return "".join(stack)