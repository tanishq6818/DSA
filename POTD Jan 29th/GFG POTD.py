# // Given a string str consisting of digits, you can divide it into sub-groups by separating the string into substrings. For example, "112" can be divided as {"1", "1", "2"}, {"11", "2"}, {"1", "12"}, and {"112"}.

# // A valid grouping can be done if you are able to divide sub-groups where the sum of digits in a sub-group is less than or equal to the sum of the digits of the sub-group immediately right to it. Your task is to determine the total number of valid groupings that could be done for a given string.

# // Example 1: 

# // Input: 
# // str = "1119"
# // Output: 
# // 7
# // Explanation: 
# // One valid grouping is {"1", "11", "9"}.
# // Sum of digits of first sub-group ("1") is 1,
# // for the second sub-group ("11"), it is 2,
# // and for the third one ("9"), it is 9.
# // As the sum of digits of the sub-groups is 
# // in increasing order, it forms a valid grouping.
# // Other valid grouping are {"1", "119"}, {"1","1","19"}, 
# // {"1","1","1","9"}, {"11","19"}, {"111","9"} and {"1119"}
# // are six other valid groupings.
# // Example 2:

# // Input: 
# // str = "12"
# // Output: 
# // 2
# // Explanation: 
# // {"1","2"} and {"12"} are two valid groupings.
# // Your Task:
# // You don't need to read or print anything. Your task is to complete the function TotalCount() which takes the string str as input parameter and returns total possible groupings.

# // Expected Time Complexity: O(N3) where N is the length of the string.
# // Expected Space Complexity: O(N2)

# // Constraints:
# // 1 <= N <= 100
# // stri ∈ {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}

class Solution:
    def TotalCount(self, s):
        # Code here
        n=len(s) #Get the length of the string
        maxl=100 #Set the maximum length for dp array
        dp=[[-1 for i in range(9*maxl+1)] for i in range(maxl)] #Initialize dp array with -1

        # Define a recursive helper function
        def helper(p,psum):
            if p==n: # If we have reached the end of the string
                return 1 # Return 1 to indicate a valid combination
            if dp[p][psum]!=(-1): # If the value is already evaluated
                return dp[p][psum] # Return the stored value

            ans=0
            sumd=0
            dp[p][psum]=0

            # Iterate over the string starting from position p
            for i in range(p,n):
                sumd+=int(s[i]) # Calculate the sum of digits from position p to i
                if sumd>=psum: # If the sum is greater than or equal to psum
                    ans+=helper(i+1,sumd) # Recursively call the helper function
            dp[p][psum]=(ans) # Store the result in dp array
            return dp[p][psum] # Return the result

        return helper(0,0) # Call the helper function to get the final answer 
