// Given an array of n integers. Find the minimum positive number to be inserted in array, so that sum of all elements of array becomes prime.

// Example 1:

// Input:
// N=5
// arr = {2, 4, 6, 8, 12}
// Output:  
// 5
// Explanation: 
// The sum of the array is 32 ,we can add 5 to this to make it 37 which is a prime number.
// Example 2:

// Input:
// N=3
// arr = {1, 5, 7}
// Output:  
// 0 
// Explanation: 
// The sum of the array is 13 which is already prime. 
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function minNumber() that takes array arr and integer N as input parameters and returns the minimum positive number to be inserted in the array so as to make it's sum a prime number.

// Expected Time Complexity: O(N log(log N))
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 ≤ N ≤ 105
// 1 ≤ sum of all elements ≤ 106

class Solution
{
    int MAX;
    bool isPrime[1000005];
    
    public:
    void sieveOfEratostheneses()
    {
        memset(isPrime, true, sizeof(isPrime));
        isPrime[1] = false;
        for (int i = 2; i * i < MAX; i++) {
            if (isPrime[i]) {
                for (int j = 2 * i; j < MAX; j += i)
                    isPrime[j] = false;
            }
        }
    }
    int findPrime(int n)
    {
        int num = n + 1;
        while (num) {
            if (isPrime[num])
                return num;
            num = num + 1;
        }
        return 0;
    }
    int minNumber(int arr[],int n)
    {
        MAX = 1000005;
        sieveOfEratostheneses();
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i];
        if (isPrime[sum])
            return 0;
        int num = findPrime(sum);
        return num - sum;
    }
};
