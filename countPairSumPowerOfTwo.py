# Python3 program to implement
# the above approach
from math import pow

# Function to count all pairs
# whose sum is a power of two
def countPair(arr, n):
	# Stores the frequency of
	# each element of the array
	m = {}
	# Update frequency of
	# array elements
	for i in range(n):
		m[arr[i]] = m.get(arr[i], 0) + 1
	# Stores count of
	# required pairs
	ans = 0
	for i in range(31):
		# Current power of 2
		key = int(pow(2, i))
		# Traverse the array
		for j in range(n):
			k = key - arr[j]
			# If pair does not exist
			if k not in m:
				continue
			# Increment count of pairs
			else:
				ans += m.get(k, 0)
			if (k == arr[j]):
				ans += 1
	# Return the count of pairs
	return ans // 2

# Driver Code
if __name__ == '__main__':
	arr = [ 1, 8, 2, 10, 6 ]
	n = len(arr)
	print(countPair(arr, n))

# This code is contributed by SURENDRA_GANGWAR
