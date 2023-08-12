// Given an array of integers, find the length of the longest (strictly) increasing subsequence from the given array.

// Example 1:

// Input:
// N = 16
// A = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15}
// Output: 
// 6
// Explanation:
// There are more than one LIS in this array. One such Longest increasing subsequence is {0,2,6,9,13,15}.
// Example 2:

// Input:
// N = 6
// A[] = {5,8,3,7,9,1}
// Output: 
// 3
// Explanation:
// There are more than one LIS in this array.  One such Longest increasing subsequence is {5,7,9}.
// Your Task:
// Complete the function longestSubsequence() which takes the input array and its size as input parameters and returns the length of the longest increasing subsequence.

// Expected Time Complexity : O( N*log(N) )
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 ≤ N ≤ 104
// 0 ≤ A[i] ≤ 106

int longestSubsequence(int n, int a[]) {
    // Initialize a vector to store the piles
    std::vector<int> piles;

    // Loop through the array
    for (int i = 0; i < n; ++i) {
        // Find the position where the current element should be inserted in piles
        auto it = std::lower_bound(piles.begin(), piles.end(), a[i]);
        
        if (it == piles.end()) {
            // If no pile can accommodate the current element, create a new pile
            piles.push_back(a[i]);
        } else {
            // Otherwise, replace the top element of the pile with the current element
            *it = a[i];
        }
    }
    
    // The length of the longest increasing subsequence is equal to the number of piles
    return piles.size();
}
