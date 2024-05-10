// Given an array of integers arr, the length of the array n, and an integer k, find all the unique combinations in arr where the sum of the combination is equal to k. Each number can only be used once in a combination.
// Return the combinations in the lexicographically sorted order, where each combination is in non-decreasing order.

// Example 1:

// Input: 
// n = 5, k = 7
// arr[] = { 1, 2, 3, 3, 5 }
// Output:
// { { 1, 3, 3 }, { 2, 5 } }
// Explanation:
// 1 + 3 + 3 = 7
// 2 + 5 = 7
// Example 2:

// Input:
// n = 6, k = 30
// arr[] = { 5, 10, 15, 20, 25, 30 }
// Output:
// { { 5, 10, 15 }, { 5, 25 }, { 10, 20 }, { 30 } }
// Explanation:
// 5 + 10 + 15 = 30
// 5 + 25 = 30
// 10 + 20 = 30
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function CombinationSum2() which takes arr[],n, and k as input parameters and returns all the unique combinations.
 

// Constraints:
// 1 <= n <= 100
// 1 <= arr[i] <= 50
// 1 <= k <= 30

// let p = number of elements, at maximum, can sum up to the given value k.

// Expected Time Complexity: O(2min(n,p))
// Expected Auxiliary Space: O(n)

void findCombinations(vector<int>& arr, int index, int target, vector<int>& current, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(current);
        return;
    }
    
    for (int i = index; i < arr.size(); ++i) {
        if (i > index && arr[i] == arr[i - 1]) // Skip duplicates
            continue;
        
        if (arr[i] > target) // If current element is greater than target, no need to continue
            break;
        
        current.push_back(arr[i]);
        findCombinations(arr, i + 1, target - arr[i], current, result); // Recursive call with updated target and index
        current.pop_back(); // Backtrack
    }
}

vector<vector<int>> CombinationSum2(vector<int> arr, int n, int k) {
    vector<vector<int>> result;
    vector<int> current;
    
    sort(arr.begin(), arr.end()); // Sort the array to handle duplicates
    
    findCombinations(arr, 0, k, current, result);
    
    return result;
}
