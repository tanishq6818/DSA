// A gallery with plants is divided into n parts, numbered 0, 1, 2, 3, ..., n-1. There are provisions for attaching water sprinklers in every division. A sprinkler with range x at division i can water all divisions from i-x to i+x.

// Given an array gallery[] consisting of n integers, where gallery[i] is the range of the sprinkler at partition i (a power of -1 indicates no sprinkler attached), return the minimum number of sprinklers that need to be turned on to water the entire gallery. If there is no possible way to water the full length using the given sprinklers, print -1.

// Example 1:

// Input:
// n = 6
// gallery[] = {-1, 2, 2, -1, 0, 0}
// Output:
// 2
// Explanation: 
// Sprinklers at index 2 and 5
// can water the full gallery, span of
// sprinkler at index 2 = [0,4] and span
// of sprinkler at index 5 = [5,5].
// Example 2:

// Input:
// n = 9
// gallery[ ] = {2, 3, 4, -1, 2, 0, 0, -1, 0}
// Output:
// -1
// Explanation: 
// No sprinkler can throw water
// at index 7. Hence all plants cannot be
// watered.
// Example 3:

// Input:
// n = 9
// gallery[ ] = {2, 3, 4, -1, 0, 0, 0, 0, 0}
// Output:
// 3
// Explanation: 
// Sprinkler at indexes 2, 7 and
// 8 together can water all plants.
// Your task:
// You do not have to take any input or print anything. Your task is to complete the function min_sprinklers() which takes the array gallery[ ] and the integer n as input parameters and returns the minimum number of sprinklers that need to be turned on to water the entire gallery.

// Expected Time Complexity: O( nlog(n) )
// Expected Auxiliary Space: O( n )

// Constraints:
// 1 ≤ n ≤ 105
// gallery[i] ≤ 50


int min_sprinklers(int gallery[], int n) {
    // Create a vector of pairs to store start and end points of effective ranges
    vector<pair<int, int>> sprinklerRanges;

    // Fill the vector with start and end points of effective ranges
    for (int i = 0; i < n; ++i) {
        if (gallery[i] != -1) {
            sprinklerRanges.push_back({max(0, i - gallery[i]), min(n - 1, i + gallery[i])});
        }
    }

    // Sort the vector based on start points
    sort(sprinklerRanges.begin(), sprinklerRanges.end());

    int start = 0, end = 0, sprinklerCount = 0;

    // Iterate through the sorted vector and update the effective range
    for (int i = 0; i < sprinklerRanges.size(); ++i) {
        if (sprinklerRanges[i].first > end) {
            return -1; // Cannot cover the entire gallery
        }

        end = max(end, sprinklerRanges[i].second);

        if (end >= n - 1) {
            return sprinklerCount + 1; // All plants are covered
        }

        if (sprinklerRanges[i].first > start) {
            start = end;
            sprinklerCount++;
        }
    }

    return -1; // If the end pointer did not reach the end of the gallery
}
