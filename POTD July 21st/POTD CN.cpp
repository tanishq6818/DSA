// Problem Statement

// You are given an array 'arr' consisting of 'n'integers which denote the position of a stall.

// You are also given an integer 'k' which denotes the number of aggressive cows.

// You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.

// Print the maximum possible minimum distance.

// Example:

// Input: 'n' = 3, 'k' = 2 and 'arr' = {1, 2,

// 3)

// Output: 2

// Explanation: The maximum possible minimum distance will be 2 when 2 cows are placed at positions (1, 3). Here distance between cows is 2.

bool canPlaceCows(const vector<int>& stalls, int k, int minDistance) {
    int cowsPlaced = 1;
    int lastPos = stalls[0];

    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPos >= minDistance) {
            cowsPlaced++;
            lastPos = stalls[i];
        }
    }

    return cowsPlaced >= k;
}

int aggressiveCows(vector<int> &stalls, int k) {
    sort(stalls.begin(), stalls.end());

    int left = 1; // Minimum possible distance
    int right = stalls.back() - stalls.front(); // Maximum possible distance
    int ans = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canPlaceCows(stalls, k, mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return ans;
}
    
