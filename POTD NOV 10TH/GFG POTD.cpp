// Given a pattern containing only I's and D's. I for increasing and D for decreasing. Devise an algorithm to print the minimum number following that pattern. Digits from 1-9 and digits can't repeat.

// Example 1:

// Input:
// D
// Output:
// 21
// Explanation:
// D is meant for decreasing, so we choose the minimum number among all possible numbers like 21,31,54,87,etc.
// Example 2:

// Input:
// IIDDD
// Output:
// 126543
// Explanation:
// Above example is self- explanatory,
// 1 < 2 < 6 > 5 > 4 > 3
//   I - I - D - D - D
// Your Task:

// You don't need to read input or print anything. Your task is to complete the function printMinNumberForPattern() which takes the string S and returns a string containing the minimum number following the valid number.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ Length of String ≤ 8

//Back-end complete function template for C++

class Solution{   
public:
    string printMinNumberForPattern(string S){
        
        // Initialize current_max (to make sure that 
        // we don't use repeated character 
        int curr_max = 0; 
      
        // Initialize last_entry (Keeps track for 
        // last printed digit) 
        int last_entry = 0; 
      
        int j; 
        string ans="";
        // Iterate over input array 
        for (int i=0; i<S.length(); i++) 
        { 
            // Initialize 'noOfNextD' to get count of 
            // next D's available 
            int noOfNextD = 0; 
      
            switch(S[i]) 
            { 
            case 'I': 
                // If letter is 'I' 
      
                // Calculate number of next consecutive D's 
                // available 
                j = i+1; 
                while (S[j] == 'D' && j < S.length()) 
                { 
                    noOfNextD++; 
                    j++; 
                } 
                    
                if (i==0) 
                { 
                    curr_max = noOfNextD + 2; 
      
                    // If 'I' is first letter, print incremented 
                    // sequence from 1 
                    ++last_entry;
                    ans+=('0'+last_entry);
                    ans+=('0'+curr_max);

                    // Set max digit reached 
                    last_entry = curr_max; 
                } 
                else
                { 
                    // If not first letter 
      
                    // Get next digit to print 
                    curr_max = curr_max + noOfNextD + 1; 
      
                    // Print digit for I 
                    last_entry = curr_max; 
                    ans+=('0'+last_entry);
                } 
      
                // For all next consecutive 'D' print  
                // decremented sequence 
                for (int k=0; k<noOfNextD; k++) 
                {   
                    --last_entry;
                    ans+=('0'+last_entry);
                    i++; 
                } 
                break; 
      
            // If letter is 'D' 
            case 'D': 
                if (i == 0) 
                { 
                    // If 'D' is first letter in sequence 
                    // Find number of Next D's available 
                    j = i+1; 
                    while (S[j] == 'D' && j < S.length()) 
                    { 
                        noOfNextD++; 
                        j++; 
                    } 
      
                    // Calculate first digit to print based on  
                    // number of consecutive D's 
                    curr_max = noOfNextD + 2; 
      
                    // Print twice for the first time 
                    ans+=('0'+curr_max);
                    ans+=('0'+(curr_max - 1));

      
                    // Store last entry 
                    last_entry = curr_max - 1; 
                } 
                else
                { 
                    // If current 'D' is not first letter 
      
                    // Decrement last_entry 
                    ans+=('0'+(last_entry - 1));
                    //cout << " " << last_entry - 1; 
                    last_entry--; 
                } 
                break; 
            } 
        } 
        return ans;
        
        
    }
};
