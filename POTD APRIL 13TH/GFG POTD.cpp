// Given a number x, reverse its binary form and return the answer in decimal.

// Example 1:

// Input:
// x = 1
// Output:
// 2147483648 
// Explanation:
// Binary of 1 in 32 bits representation-
// 00000000000000000000000000000001
// Reversing the binary form we get, 
// 10000000000000000000000000000000,
// whose decimal value is 2147483648.
// Example 2:

// Input:
// x = 5
// Output:
// 2684354560 
// Explanation:
// Binary of 5 in 32 bits representation-
// 00000000000000000000000000000101
// Reversing the binary form we get, 
// 10100000000000000000000000000000,
// whose decimal value is 2684354560.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function reversedBits() which takes an Integer x as input and returns the reverse binary form of x in decimal form.

// Expected Time Complexity: O(log (x))
// Expected Auxiliary Space: O(1)

// Constraints:
// 0  <=  x  <  232

long long reversedBits(long long x) {
        
        if(x==0)
            return 0;
        string s = bitset<32>(x).to_string(); 
        s = s.substr(s.find('1')); // Remove leading zeros
        
        long long y = 32 - s.length();
        
        s = string(y, '0') + s; // Adding leading zeroes to fill 32 bits
        
        // Reverse the binary
        reverse(s.begin(), s.end());
        
        // Change binary to its Integer Form
        long long ans = bitset<32>(s).to_ulong(); 
        return ans;
    }
