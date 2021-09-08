def shuffleThePieces(arr, pieces):
    hashSet = set()
    for piece in pieces:
        hashSet.add(tuple(piece))
    n = len(arr)
    dp = [False for _ in range(n+1)]
    dp[0] = True
    # dp[i+1]: t/f for arr ending at arr[i]
    for i in range(n):
        for j in range(i):
            if dp[j] and tuple(arr[j:i]) in hashSet:
                dp[i+1] = True
    return dp[n]

print(shuffleThePieces([1, 2, 5, 3], [[5], [1, 2], [3]]))
print(shuffleThePieces([1, 2, 5, 3, 6], [[1, 2], [5], [6, 3]]))