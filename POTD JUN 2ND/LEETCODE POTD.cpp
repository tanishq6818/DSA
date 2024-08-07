Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

 

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
 

Constraints:

1 <= s.length <= 105
s[i] is a printable ascii character.

  void reverseString(std::vector<char>& s) {
    int left = 0;
    int right = s.size() - 1;
    
    while (left < right) {
        // Swap characters at left and right indices
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        
        // Move left pointer to the right and right pointer to the left
        left++;
        right--;
    }
}
