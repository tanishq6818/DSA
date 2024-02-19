// Given a string s of lowercase alphabets and a number k, the task is to print the minimum value of the string after removal of k characters. The value of a string is defined as the sum of squares of the count of each distinct character present in the string. 

// Example 1:

// Input: 
// s = abccc, k = 1
// Output: 
// 6
// Explaination:
// We remove c to get the value as 12 + 12 + 22
// Example 2:

// Input: 
// s = aabcbcbcabcc, k = 3
// Output: 
// 27
// Explaination: 
// We remove two 'c' and one 'b'. Now we get the value as 32 + 32 + 32.
// Your Task:
// You do not need to read input or print anything. Your task is to complete the function minValue() which takes s and k as input parameters and returns the minimum possible required value.

// Expected Time Complexity: O(n+klog(p))  where n is the length of string and p is number of distinct alphabets and k number of alphabets to be removed. 
// Expected Auxiliary Space: O(n)

// Constraints:
// 0 ≤ k ≤ |string length| ≤ 105

int minValue(string s, int k){
        //Map to store the frequency of each character.
        map<char, int> mp;
        //Priority queue to store the frequencies in descending order.
        priority_queue<int> pq;
        
        //Iterating through the string to count the frequency of each character.
        for(int i = 0;i < s.size();i++)
            mp[s[i]]++;
        
        //Pushing the frequencies into the priority queue.
        for(auto it = mp.begin();it != mp.end();it++)
            pq.push(it->second);
        
        //Decreasing the frequencies k times to obtain the minimum value.
        while(k--){
            int x = pq.top();
            x--;
            pq.pop();
            pq.push(x);
        }
        
        //Calculating the result by squaring the remaining frequencies in the priority queue.
        int result = 0;
        while(!pq.empty()){
            int x = pq.top();
            pq.pop();
            result += (x*x);
        }
        
        //Returning the minimum value.
        return result;
    }
