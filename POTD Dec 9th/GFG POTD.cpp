Given a number n, the task is to find out whether this number is a Smith number or not. A Smith number is a composite number whose sum of digits is equal to the sum of digits of its prime factors.

Example 1:

Input:
n = 4
Output:
1
Explanation:
The sum of the digits of 4 is 4, and the sum of the digits of its prime factors is 2 + 2 = 4.
Example 2:

Input:
n = 378
Output:
1
Explanation:
378 = 21*33*71 is a Smith number since 3+7+8 = 2*1+3*3+7*1.
Your Task:
You don't need to read input or print anything. Your task is to complete the function smithNum() which takes an Integer n as input and returns the answer.

Expected Time Complexity: O(n * log(n))
Expected Auxiliary Space: O(n)

Constraints:
1 <= n <= 105



  
class Solution {
  public:
  
    const int MAX  = 100000;
 
    // array to store all prime less than and equal to 10^6
    vector <int> primes;
     
    // utility function for sieve of sundaram
    void sieveSundaram()
    {
        // In general Sieve of Sundaram, produces primes smaller
        // than (2*x + 2) for a number given number x. Since
        // we want primes smaller than MAX, we reduce MAX to half
        // This array is used to separate numbers of the form
        // i+j+2ij from others where 1 <= i <= j
        bool marked[MAX/2 + 100] = {0};
     
        // Main logic of Sundaram. Mark all numbers which
        // do not generate prime number by doing 2*i+1
        for (int i=1; i<=(sqrt(MAX)-1)/2; i++)
            for (int j=(i*(i+1))<<1; j<=MAX/2; j=j+2*i+1)
                marked[j] = true;
     
        // Since 2 is a prime number
        primes.push_back(2);
     
        // Print other primes. Remaining primes are of the
        // form 2*i + 1 such that marked[i] is false.
        for (int i=1; i<=MAX/2; i++)
            if (marked[i] == false)
                primes.push_back(2*i + 1);
    }
     
    // Returns true if n is a Smith number, else false.
    bool isSmith(int n)
    {
        int original_no = n;
     
        // Find sum the digits of prime factors of n
        int pDigitSum = 0;
        for (int i = 0; primes[i] <= n/2; i++)
        {
            while (n % primes[i] == 0)
            {
                // If primes[i] is a prime factor,
                // add its digits to pDigitSum.
                int p = primes[i];
                n = n/p;
                while (p > 0)
                {
                    pDigitSum += (p % 10);
                    p = p/10;
                }
            }
        }
     
        // If n!=1 then one prime factor still to be
        // summed up;
        if (n != 1 && n != original_no)
        {
            while (n > 0)
            {
                pDigitSum = pDigitSum + n%10;
                n = n/10;
            }
        }
     
        // All prime factors digits summed up
        // Now sum the original number digits
        int sumDigits = 0;
        while (original_no > 0)
        {
            sumDigits = sumDigits + original_no % 10;
            original_no = original_no/10;
        }
     
        // If sum of digits in prime factors and sum
        // of digits in original number are same, then
        // return true. Else return false.
        return (pDigitSum == sumDigits);
    }
    
    int smithNum(int n) {
        
        sieveSundaram();
        
        if(isSmith(n))
            return 1;
        else
            return 0;
    }
};
