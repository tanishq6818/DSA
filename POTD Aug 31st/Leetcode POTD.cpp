1326. Minimum Number of Taps to Open to Water a Garden

There is a one-dimensional garden on the x-axis. The garden starts at the point 0 and ends at the point n. (i.e The length of the garden is n).

There are n + 1 taps located at points [0, 1, ..., n] in the garden.

Given an integer n and an integer array ranges of length n + 1 where ranges[i] (0-indexed) means the i-th tap can water the area [i - ranges[i], i + ranges[i]] if it was open.

Return the minimum number of taps that should be open to water the whole garden, If the garden cannot be watered return -1.

 

Example 1:


Input: n = 5, ranges = [3,4,1,1,0,0]
Output: 1
Explanation: The tap at point 0 can cover the interval [-3,3]
The tap at point 1 can cover the interval [-3,5]
The tap at point 2 can cover the interval [1,3]
The tap at point 3 can cover the interval [2,4]
The tap at point 4 can cover the interval [4,4]
The tap at point 5 can cover the interval [5,5]
Opening Only the second tap will water the whole garden [0,5]
Example 2:

Input: n = 3, ranges = [0,0,0,0]
Output: -1
Explanation: Even if you activate all the four taps you cannot water the whole garden.

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        // Create a vector to track the maximum reach for each position
        vector<int> maxReach(n + 1);

        // Calculate the maximum reach for each tap
        for (int i = 0; i < ranges.size(); i++) {
            // Calculate the leftmost position the tap can reach
            int start = max(0, i - ranges[i]);
            // Calculate the rightmost position the tap can reach
            int end = min(n, i + ranges[i]);

            // Update the maximum reach for the leftmost position
            maxReach[start] = max(maxReach[start], end);
        }
        
        // Number of taps used
        int taps = 0;
        // Current rightmost position reached
        int currEnd = 0;
        // Next rightmost position that can be reached
        int nextEnd = 0;

        // Iterate through the garden
        for (int i = 0; i <= n; i++) {
            // Current position cannot be reached
            if (i > nextEnd) {
                return -1;
            }

            // Increment taps when moving to a new tap
            if (i > currEnd) {
                taps++;
                // Move to the rightmost position that can be reached
                currEnd = nextEnd;
            }

            // Update the next rightmost position that can be reached
            nextEnd = max(nextEnd, maxReach[i]);
        }

        // Return the minimum number of taps used
        return taps;
    }
};
