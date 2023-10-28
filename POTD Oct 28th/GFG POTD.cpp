
// Given an integer, check whether it is Bleak or not.

// A number n is called Bleak if it cannot be represented as sum of a positive number x and set bit count in x, i.e., x + countSetBits(x) is not equal to n for any non-negative number x.

// Example 1:

// Input: 
// 4
// Output: 
// 1
// Explanation: 
// There is no x such that x + countSetbit(x) = 4
// Example 2:

// Input: 
// 3
// Output: 
// 0
// Explanation: 
// 3 is a Bleak number as 2 + countSetBit(2) = 3.
// Your Task:
// You don't need to read or print anything. Your task is to complete the function is_bleak() which takes n as input parameter and returns 1 if n is not a Bleak number otherwise returns 0.

// Expected Time Complexity: O(log(n) * log(n))
// Expected Space Complexity: O(1)
 
// Constraints:
// 1 <= n <= 109

int count_setbit(int n)
    {
        int cnt = 0;
        //iterating until n becomes 0.
        while (n > 0)
        {
            //checking if the rightmost bit is set.
            if (n & 1)
                cnt++;
            //shifting n to the right by 1 bit.
            n >>= 1;
        }
        //returning the count of set bits.
        return cnt;
    }

    //Function to check if a number is bleak or not.
    int is_bleak(int n)
    {
        //calculating the maximum number of non-zero bits in n.
        int k = ceil(log2(n * 1.0) * 1.0);
        //iterating over all the numbers in the range [n-k, n].
        for (int i = n - k; i <= n; i++)
        {
            //checking if i plus the count of set bits in i is equal to n.
            if (i + count_setbit(i) == n)
            {
                //if yes, then n is not a bleak number.
                return 0;
            }
        }
        //if no such number is found, then n is a bleak number.
        return 1;
    }
