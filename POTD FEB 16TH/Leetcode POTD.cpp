// Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.

 

// Example 1:

// Input: arr = [5,5,4], k = 1
// Output: 1
// Explanation: Remove the single 4, only 5 is left.
// Example 2:
// Input: arr = [4,3,1,1,3,3,2], k = 3
// Output: 2
// Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.
 

// Constraints:

// 1 <= arr.length <= 10^5
// 1 <= arr[i] <= 10^9
// 0 <= k <= arr.length

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // Map to track of the frequencies of elements
        unordered_map<int, int> map;
        for (int i : arr) {
            map[i]++;
        }
        
        // Min heap to track all the frequencies
        priority_queue<int, vector<int>, greater<int> > frequencies;
        for (auto it : map) {
            frequencies.push(it.second);
        }

        // Tracking the number of elements removed
        int elementsRemoved = 0;
        
        // Traversing all frequencies
        while (!frequencies.empty()) {
            // Removing the least frequent element
            elementsRemoved += frequencies.top();

            // If the number of elements removed exceeds k, return
            // the remaining number of unique elements
            if (elementsRemoved > k) {
                return frequencies.size();
            }
            frequencies.pop();
        }
        
        // We have removed all elements, so no unique integers remain
        // Return 0 in this case
        return 0;
    }
};
