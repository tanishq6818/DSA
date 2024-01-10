// Given an array arr containing N integers and a positive integer K, find the length of the longest sub array with sum of the elements divisible by the given value K.

// Example 1:

// Input:
// N = 6, K = 3
// arr[] = {2, 7, 6, 1, 4, 5}
// Output: 
// 4
// Explanation:
// The subarray is {7, 6, 1, 4} with sum 18, which is divisible by 3.
// Example 2:

// Input:
// N = 7, K = 3
// arr[] = {-2, 2, -5, 12, -11, -1, 7}
// Output: 
// 5
// Explanation:
// The subarray is {2,-5,12,-11,-1} with sum -3, which is divisible by 3.
// Your Task:
// The input is already taken care of by the driver code. You only need to complete the function longSubarrWthSumDivByK() that takes an array arr, sizeOfArray n and a  positive integer K, and returns the length of the longest subarray which has sum divisible by K. 

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 <= N <= 105
// 1 <= K <= 109
// -109 <= A[i] <= 109 
int longSubarrWthSumDivByK(int arr[], int n, int k) {
    // Create a hash map to store the remainder and its corresponding index
    unordered_map<int, int> remainderIndexMap;
    
    int sum = 0;
    int maxLength = 0;

    for (int i = 0; i < n; i++) {
        // Calculate the prefix sum
        sum += arr[i];

        // Calculate the remainder when divided by K
        int remainder = ((sum % k) + k) % k;

        // If remainder is 0, update maxLength to the current index + 1
        if (remainder == 0)
            maxLength = i + 1;
        else {
            // Check if the current remainder is present in the map
            // If present, update maxLength with the difference between current index and the index stored in the map
            if (remainderIndexMap.find(remainder) != remainderIndexMap.end())
                maxLength = max(maxLength, i - remainderIndexMap[remainder]);
        }

        // If remainder is not present in the map, store it along with its index
        if (remainderIndexMap.find(remainder) == remainderIndexMap.end())
            remainderIndexMap[remainder] = i;
    }

    return maxLength;
}
