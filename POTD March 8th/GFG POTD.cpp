// Given a string s which contains only lower alphabetic characters, check if it is possible to remove at most one character from this string in such a way that frequency of each distinct character becomes same in the string. Return true if it is possible to do else return false.

// Note: The driver code print 1 if the value returned is true, otherwise 0.

// Example 1:

// Input:
// s = "xyyz"
// Output: 
// 1 
// Explanation: 
// Removing one 'y' will make frequency of each character to be 1.
// Example 2:

// Input:
// s = "xxxxyyzz"
// Output: 
// 0
// Explanation: 
// Frequency can not be made same by removing at most one character.
// Your Task:  
// You dont need to read input or print anything. Complete the function sameFreq() which takes a string as input parameter and returns a boolean value denoting if same frequency is possible or not.

// Expected Time Complexity: O(|s|) 
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= |s| <= 105


class Solution{
public:
	 
	// Utility method to get index of character ch
	// in lower alphabet characters
	int getIdx(char ch)
	{
	    return (ch - 'a');
	}
	 
	// Returns true if all non-zero elements
	// values are same
	bool allSame(int freq[], int N)
	{
	    int same;
	 
	    //  get first non-zero element
	    int i;
	    for (i = 0; i < N; i++)
	    {
	        if (freq[i] > 0)
	        {
	            same = freq[i];
	            break;
	        }
	    }
	 
	    //  check equality of each element with variable same
	    for (int j = i+1; j < N; j++)
	        if (freq[j] > 0 && freq[j] != same)
	            return false;
	 
	    return true;
	}
	 
	// Returns true if we can make all character
	// frequencies same
	bool sameFreq(string str)
	{
	    int M = 26; // size of hash map for all 26 letters
	    int l = str.length();
	 
	    //  fill frequency array
	    int freq[M] = {0};
	    for (int i = 0; i < l; i++)
	        freq[getIdx(str[i])]++;
	 
	    //  if all frequencies are same, then return true
	    if (allSame(freq, M))
	        return true;
	 
	    /*  Try decreasing frequency of all character
	        by one and then check all equality of all
	        non-zero frequencies */
	    for (char c = 'a'; c <= 'z'; c++)
	    {
	        int i = getIdx(c);
	 
	        // Check character only if it occurs in str
	        if (freq[i] > 0)
	        {
	            freq[i]--;
	 
	            if (allSame(freq, M))
	                return true;
	            freq[i]++;
	        }
	    }
	 
	    return false;
	}

   
};
