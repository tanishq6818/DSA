int minDiff(int n, vector<int> arr) {
    // Sort the array
    sort(arr.begin(), arr.end());

    int minDifference = INT_MAX;
    
    // Compare adjacent elements to find the minimum difference
    for (int i = 1; i < n; ++i) {
        int diff = arr[i] - arr[i - 1];
        if (diff < minDifference) {
            minDifference = diff;
        }
    }
    
    return minDifference;
}
