Given an array, arr of integers, and another number target, find three integers in the array such that their sum is closest to the target. Return the sum of the three integers.

Note: If there are multiple solutions, return the maximum one.

Examples :

Input: arr[] = [-7, 9, 8, 3, 1, 1], target = 2
Output: 2
Explanation: There is only one triplet present in the array where elements are -7,8,1 whose sum is 2.
Input: arr[] = [5, 2, 7, 5], target = 13
Output: 14
Explanation: There is one triplet with sum 12 and other with sum 14 in the array. Triplet elements are 5, 2, 5 and 2, 7, 5 respectively. Since abs(13-12) ==abs(13-14) maximum triplet sum will be preferred i.e 14.
Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(1)

Constraints:
3 ≤ arr.size() ≤ 103
-105 ≤ arr[i] ≤ 105
1 ≤ target ≤ 105


  int threeSumClosest(std::vector<int>& arr, int target) {
    int n = arr.size();
    if (n < 3) return 0; // According to constraints, should never happen

    std::sort(arr.begin(), arr.end());

    int closestSum = INT_MAX;
    int minDiff = INT_MAX;

    for (int i = 0; i < n - 2; ++i) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = arr[i] + arr[left] + arr[right];
            int diff = std::abs(sum - target);

            if (diff < minDiff || (diff == minDiff && sum > closestSum)) {
                minDiff = diff;
                closestSum = sum;
            }

            if (sum < target) {
                ++left;
            } else {
                --right;
            }
        }
    }

    return closestSum;
}
