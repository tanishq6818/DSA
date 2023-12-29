Given a string s, check if it is possible to convert it into a string that is the repetition of a substring of length k. Conversion has to be done by following the steps mentioned below only once:

Select two indices i and j (zero-based indexing, i could be equal to j), such that i and j are divisible by k.
Select substrings of length k starting from indices i and j.
Replace substring starting at index i with substring starting at index j within the string.
Example 1:

Input:
N = 4
K = 2
S = "bdac"
Output: 1
Explanation: We can replace either
"bd" with "ac" or "ac" with "bd"
Example 2:

Input: 
N = 5
K = 2
S = "abcde"
Output: 0
Explanation: Since n % k != 0, it's not 
possible to convert s into a string which
is a concatanation of a substring with 
length k.
Your Task:
You don't need to read input or print anything. Your task is to complete the function kSubstrConcat() which takes a string s, its length n and an integer k as inputs and return 1 if convertion of the given string is possible, else 0.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).

Constraints:
2 <= k < n <= 105
  class Solution{

public:

	//Function to check if a given string can be divided into substrings of size k
	int kSubstrConcat (int n, string s, int k)
	{
		//if n is equal to k, return 1
		if (n == k) return 1;

		//if n is not divisible by k, return 0
		if (n % k != 0) return 0;
		
		//mapping substrings of size k and their frequency
		unordered_map <string, int> m;
		for (int i = 0; i < n; i += k)
		{
			m[s.substr (i, k)]++;
		}

		//if only one unique substring is found, return 1
		if (m.size () == 1) return 1;
		
		//if more than 2 unique substrings are found, return 0
		if (m.size () != 2) return 0;

		//if the frequency of one substring is (n/k - 1) or 1, return 1
		if (m.begin()->second == (n / k - 1) || m.begin()->second == 1)
			return 1;
			
		//otherwise, return 0
		return 0;
	}

};
