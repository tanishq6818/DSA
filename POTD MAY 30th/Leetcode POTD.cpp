Given an array of integers arr.

We want to select three indices i, j and k where (0 <= i < j <= k < arr.length).

Let's define a and b as follows:

a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
Note that ^ denotes the bitwise-xor operation.

Return the number of triplets (i, j and k) Where a == b.

 

Example 1:

Input: arr = [2,3,1,6,7]
Output: 4
Explanation: The triplets are (0,1,2), (0,2,2), (2,3,4) and (2,4,4)
Example 2:

Input: arr = [1,1,1,1,1]
Output: 10
 

Constraints:

1 <= arr.length <= 300
1 <= arr[i] <= 108

  class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int size = arr.size();
        int count = 0;
        int prefix = 0;

        // Maps to store counts and totals of XOR values encountered
        unordered_map<int, int> countMap = {{0, 1}}, totalMap;

        // Iterating through the array
        for (int i = 0; i < size; ++i) {
            // Calculating XOR prefix
            prefix ^= arr[i];

            // Calculating contribution of current element to the result
            count += countMap[prefix]++ * i - totalMap[prefix];

            // Updating total count of current XOR value
            totalMap[prefix] += i + 1;
        }

        return count;
    }
};
