// We have a horizontal number line. On that number line, we have gas stations at positions stations[0], stations[1], ..., stations[N-1], where n = size of the stations array. Now, we add k more gas stations so that d, the maximum distance between adjacent gas stations, is minimized. We have to find the smallest possible value of d. Find the answer exactly to 2 decimal places.

// Example 1:

// Input:
// n = 10
// stations = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
// k = 9
// Output: 0.50
// Explanation: Each of the 9 stations can be added mid way between all the existing adjacent stations.
// Example 2:

// Input:
// n = 10
// stations = [3,6,12,19,33,44,67,72,89,95] 
// k = 2 
// Output: 14.00 
// Explanation: Construction of gas stations at 8th(between 72 and 89) and 6th(between 44 and 67) locations.
 

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function findSmallestMaxDist() which takes a list of stations and integer k as inputs and returns the smallest possible value of d. Find the answer exactly to 2 decimal places.

// Expected Time Complexity: O(n*log k)
// Expected Auxiliary Space: O(1)

// Constraint:
// 10 <= n <= 5000 
// 0 <= stations[i] <= 109 
// 0 <= k <= 105

bool canPlaceStations(const vector<int>& stations, int k, double maxDist) {
    int needed_stations = 0;
    for (int i = 1; i < stations.size(); ++i) {
        double dist = stations[i] - stations[i - 1];
        if (dist > maxDist) {
            needed_stations += ceil(dist / maxDist) - 1;
        }
    }
    return needed_stations <= k;
}

double findSmallestMaxDist(vector<int>& stations, int k) {
    double left = 0, right = stations.back() - stations.front();

    while (right - left > 1e-6) {
        double mid = (left + right) / 2;
        if (canPlaceStations(stations, k, mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }

    return round(right * 100) / 100.0;
}
