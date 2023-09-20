# You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.

# Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.

 

# Example 1:

# Input: nums = [1,1,4,2,3], x = 5
# Output: 2
# Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
# Example 2:

# Input: nums = [5,6,7,8,9], x = 4
# Output: -1
# Example 3:

# Input: nums = [3,2,20,1,1,3], x = 10
# Output: 5
# Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.
def minOperations(self, nums: List[int], x: int) -> int:
        total_sum = sum(nums)
        target = total_sum - x
        n = len(nums)
        
        if target == 0:
            return n  # If target is 0, you can remove all elements
        
        left, right = 0, 0
        current_sum = 0
        min_operations = float('inf')
        
        while right < n:
            current_sum += nums[right]
            right += 1
            
            while current_sum > target and left < right:
                current_sum -= nums[left]
                left += 1
            
            if current_sum == target:
                min_operations = min(min_operations, n - (right - left))
        
        return min_operations if min_operations != float('inf') else -1
