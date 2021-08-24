# https://oss.1point3acres.cn/forum/202012/14/074617jpv2s77424w3276h.png

def maxRevenueFromStocks(prices, algo, k):
    for i in range(len(algo)):
        if algo[i] == 0:
            algo[i] = -1

    originalRev = windowSum(prices, algo)
    curWindowSum = windowSum(prices[:k], algo[:k])
    curWindowSellSum = sum(prices[:k])
    maxDiff = curWindowSellSum - curWindowSum
    for i in range(k, len(prices)):
        curWindowSum = curWindowSum - prices[i-k] * algo[i-k] + prices[i] * algo[i]
        curWindowSellSum = curWindowSellSum - prices[i-k] + prices[i]
        maxDiff = max(maxDiff, curWindowSellSum - curWindowSum)
    
    return originalRev + maxDiff

def windowSum(prices, algo):
    rev = 0
    for i in range(len(prices)):
        rev += prices[i] * algo[i]
    return rev

prices = [2,4,1,5,2,6,7]
algo = [0,1,0,0,1,0,0]
k = 4
print(maxRevenueFromStocks(prices, algo, k))