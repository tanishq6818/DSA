// Given a non-empty array nums[] of integers of length N, find the top k elements which have the highest frequency in the array. If two numbers have same frequencies, then the larger number should be given more preference.

// Example 1:

// Input:
// N = 6
// nums = {1,1,1,2,2,3}
// k = 2
// Output: {1, 2}
// Example 2:

// Input:
// N = 8
// nums = {1,1,2,2,3,3,3,4}
// k = 2
// Output: {3, 2}
// Explanation: Elements 1 and 2 have the
// same frequency ie. 2. Therefore, in this
// case, the answer includes the element 2
// as 2 > 1.
// User Task:
// You don't have to read or print anything. You will have to complete the function topK() that takes an array nums[] and integer k as input and returns a list of top k most frequent elements. If any two elements have same frequencies, then give more preference to the larger elemet.

// Expected Time Complexity : O(NlogN)
// Expected Auxilliary Space : O(N)

// Constraints:
// 1 <= N <= 105
// 1<= nums[i] <=105
// 1 <= k <= N

vector<int> topK(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;
    
    for (int num : nums) {
        frequency[num]++;
    }
    
    vector<pair<int, int>> elementsAndFrequency;
    
    for (auto& entry : frequency) {
        elementsAndFrequency.push_back({entry.first, entry.second});
    }
    
    sort(elementsAndFrequency.begin(), elementsAndFrequency.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second) {
            return a.first > b.first;
        }
        return a.second > b.second;
    });
    
    vector<int> result;
    
    for (int i = 0; i < k; i++) {
        result.push_back(elementsAndFrequency[i].first);
    }
    
    return result;
}
