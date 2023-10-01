// Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

 

// Example 1:

// Input: s = "Let's take LeetCode contest"
// Output: "s'teL ekat edoCteeL tsetnoc"
// Example 2:

// Input: s = "God Ding"
// Output: "doG gniD"
string reverseWords(string s) {
    int start = 0;
    int end = 0;
    int n = s.length();
    
    while (end < n) {
        while (end < n && s[end] != ' ') {
            end++;
        }
        
        int left = start;
        int right = end - 1;
        
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
        
        start = end + 1;
        end++;
    }
    
    return s;
}
