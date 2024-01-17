// Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

 

// Example 1:

// Input: arr = [1,2,2,1,1,3]
// Output: true
// Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
// Example 2:

// Input: arr = [1,2]
// Output: false
// Example 3:

// Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
// Output: true

bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> countMap;

    // Count occurrences of each value in the array
    for (int num : arr) {
        countMap[num]++;
    }

    unordered_set<int> uniqueCounts;

    // Check if the count of occurrences is unique
    for (const auto& entry : countMap) {
        if (uniqueCounts.find(entry.second) != uniqueCounts.end()) {
            return false; // Duplicate count found
        }
        uniqueCounts.insert(entry.second);
    }

    return true;
}
