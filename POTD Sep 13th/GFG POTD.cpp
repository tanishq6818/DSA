// //Back-end complete function Template for C++
// Given two numbers 'N' and 'S' , find the largest number that can be formed with 'N' digits and whose sum of digits should be equals to 'S'. Return -1 if it is not possible.

// Example 1:

// Input: N = 2, S = 9
// Output: 90
// Explaination: It is the biggest number 
// with sum of digits equals to 9.
// Example 2:

// Input: N = 3, S = 20
// Output: 992
// Explaination: It is the biggest number 
// with sum of digits equals to 20.
// Your Task:
// You do not need to read input or print anything. Your task is to complete the function findLargest() which takes N and S as input parameters and returns the largest possible number. Return -1 if no such number is possible.

// Expected Time Complexity: O(N)
// Exepcted Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 104
// 0 ≤ S ≤ 105
class Solution{
public:
    //Function to find the largest number that can be made with given sum of digits.
    string findLargest(int N, int S){
        string ans = "";

        //If the sum of digits is 0 and number of digits is more than 1,
        //return -1 since it is not possible to form a number with only 0 digits.
        if(S == 0 && N > 1)
            return "-1";

        //Iterating over each digit in the number.
        for(int i = 0; i < N; i++){

            //If the sum is greater than or equal to 9,
            //we add '9' to the number and subtract 9 from the sum.
            if(S >= 9){
                ans += '9';
                S -= 9;
            }
            //If the sum is less than 9, we add the corresponding digit
            //to the number and set the sum to 0.
            else{
                ans += char(48 + S);
                S = 0;
            }
        }

        //If there is any remaining sum, it means we were not able to
        //use up the entire sum, so we return -1.
        if(S > 0)
            return "-1";

        //Returning the largest number that can be formed.
        return ans;
    }
};
