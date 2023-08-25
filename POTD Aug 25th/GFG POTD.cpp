int isPalindrome(string S)
	{
	    // Your code goes here
	    int left = 0;
        int right = S.length() - 1;
        
        while (left < right) {
            if (S[left] != S[right]) {
                return 0; // Not a palindrome
            }
            left++;
            right--;
        }
        
        return 1; // Palindrome
	}
