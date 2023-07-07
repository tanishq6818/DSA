# Given an array A[ ] of size N. Count the number of good subarrays of the given array.

# If the prefix gcd array has only distinct elements in it then the array is said to be good.
# An array pref[] is said to be prefix gcd array of array B[] if pref[i] = gcd(B[0], B[1],.. B[i])
# For exampe the array {15, 6, 19} is good as the prefix gcd array will be {15, 3, 1} which has every element distinct and the array {18, 6, 24} is bad as the prefix gcd array will be {18, 6, 6} which doesn't have every element distinct.

# Example 1:

# Input:
# N = 4
# A[] = {18, 6, 24, 1}
# Output: 
# 6
# Explanation: 
# all good subarrays are
# {18}, {6}, {24}, {1},
# {18, 6}, {24, 1}
# Example 2:

# Input:
# N = 2
# A[] = {11, 11}
# Output: 
# 2
# Explanation: 
# All good subarrays are {11}, {11}

# Your Task:  
# You don't need to read input or print anything. Your task is to complete the function solve( ), which takes integer N and array A[] as input parameters and returns the count of good subarrays.


# Constraints:
# 1 ≤ N ≤ 105
# 1 ≤ A[i] ≤ 109


def solve(self,N: int, A: List[int]) -> int:
        def gcd(a: int, b: int) -> int:
            if b == 0:
                return a
            return gcd(b, a % b)
        count = 0
    
        for i in range(N):
            distinctElements = set()
            for j in range(i, N):
                subarrayGCD = A[j] if j == i else gcd(subarrayGCD, A[j])
                if subarrayGCD not in distinctElements:
                    count += 1
                    distinctElements.add(subarrayGCD)
                else:
                    break
    
        return count
