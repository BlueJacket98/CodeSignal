def maxFrequencySubarrayUtil(A,N,M):
    i = 0
    # Stores frequency of array element
    m = {}
    # Stores the maximum frequency
    val = 0
    # Iterate for the first sub-array
    # and store the maximum
    while(i < M):
        if A[i] in m:
            m[A[i]] += 1
        else:
            m[A[i]] = 1
        val = max(val, m[A[i]])
        i += 1
    # Print the maximum frequency for
    # the first subarray
    print(val,end = " ")
    # Iterate over the range [M, N]
    for i in range(M,N,1):
        # Subtract the A[i - M] and
        # add the A[i] in the map
        if A[i - M] in m:
            m[A[i - M]] -= 1
        else:
            m[A[i - M]] = 0
        if A[i] in m:

            m[A[i]] += 1
        val = 0
        # Find the maximum frequency
        for key,value in m.items():
            val = max(val, value)
        # Print the maximum frequency
        # for the current subarray
        print(val,end=" ")

# Driver Code
if __name__ == '__main__':
    A = [1, 1, 2, 2, 3, 5]
    N = len(A)
    M = 4
    maxFrequencySubarrayUtil(A, N, M)
    # This code is contributed by ipg2016107.