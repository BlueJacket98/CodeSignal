class Solution:
    def shuffleThePieces(self, arr, pieces):
        hashMap = {}
        for piece in pieces:
            firstNum = piece[0]
            if hashMap.get(firstNum) == None:
                hashMap[firstNum] = [piece]
            else:
                hashMap[firstNum].append(piece)

        self.cnt = 0
        def dfs(combine, remain):
            if remain == []:
                if combine == arr:
                    self.cnt += 1
                return
            requiredNum = remain[0]
            if hashMap.get(requiredNum) == None:
                return
            else:
                candidates = hashMap[requiredNum]
            for i in range(len(candidates)):
                candidate = candidates[i]
                if len(candidate) > len(remain) or candidate != remain[:len(candidate)]:
                    continue
                else:
                    hashMap[requiredNum].pop(i)
                    dfs(combine + candidate, remain[len(candidate):])
                    hashMap[requiredNum].insert(i, candidate)
        
        dfs([], arr)
        if self.cnt == 0:
            return False
        else:
            return True

a = Solution()
print(a.shuffleThePieces([1, 2, 5, 3], [[5], [1, 2], [3]]))                 # True
print(a.shuffleThePieces([1, 2, 5, 3, 6], [[1, 2], [5], [6, 3]]))           # False
print(a.shuffleThePieces([5, 2, 3, 1, 4], [[5, 2], [1, 4], [3]]))           # True
print(a.shuffleThePieces([5, 2, 3, 1, 4], [[5, 2], [4, 1], [3]]))           # False