You are given an array arr. Your task is to find the longest length of a good sequence. A good sequence {x1, x2, .. xn} is an alternating sequence if its elements satisfy one of the following relations :

1.  x1 < x2 > x3 < x4 > x5. . . . . and so on
2.  x1 >x2 < x3 > x4 < x5. . . . . and so on

Examples:

Input: arr= [1, 5, 4]
Output: 3
Explanation: The entire sequenece is a good sequence.
Input: arr= [1, 17, 5, 10, 13, 15, 10, 5, 16, 8]
Output: 7
Explanation: There are several subsequences that achieve this length. 
One maximum length good subsequences is [1, 17, 10, 13, 10, 16, 8].
Expected Time Complexity: O(n)
Expected Space Complexity: O(1)

Constraints:
1 <= nums.size() <= 105 
1 <= nums[i] <= 104 

  int alternatingMaxLength(vector<int>& arr) {
    if (arr.size() == 0) return 0;
    
    int up = 1;   // Length of alternating sequence ending with increasing trend
    int down = 1; // Length of alternating sequence ending with decreasing trend
    int maxLength = 1; // Maximum length of alternating sequence found
    
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] > arr[i-1]) {
            up = down + 1;
        } else if (arr[i] < arr[i-1]) {
            down = up + 1;
        }
        // If arr[i] == arr[i-1], no change in up and down lengths
        
        // Update maxLength with the maximum of up and down
        maxLength = max(maxLength, max(up, down));
    }
    
    return maxLength;
}
