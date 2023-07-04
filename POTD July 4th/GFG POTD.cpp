def countSubArrayProductLessThanK(self, arr, n, k):
        count = 0
        product = 1
        left = 0
    
        for right in range(len(arr)):
            product *= arr[right]
    
            while product >= k and left <= right:
                product /= arr[left]
                left += 1
    
            count += right - left + 1
    
        return count
