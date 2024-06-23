Given a string str, the task is to find the bracket numbers, i.e., for each bracket in str, return i if the bracket is the ith opening or closing bracket to appear in the string. 

 Examples:

Input:  str = "(aa(bdc))p(dee)"
Output: 1 2 2 1 3 3
Explanation: The highlighted brackets in
the given string (aa(bdc))p(dee) are
assigned the numbers as: 1 2 2 1 3 3.
Input:  str = "(((()("
Output: 1 2 3 4 4 5
Explanation: The highlighted brackets in
the given string (((()( are assigned
the numbers as: 1 2 3 4 4 5
Expected Time Complexity: O(|str|)
Expected Auxiliary Space: O(|str|)

Constraints:
1 <= |str| <= 105
str contains lowercase English alphabets, and '(', ')' characters
At any index, the number of opening brackets is greater than or equal to closing brackets
vector<int> bracketNumbers(string str) {
        string temp = str;
        vector<int> ans; // vector to store the bracket numbers
        stack<int> st;   // stack to store the opening bracket numbers

        int bal = 0; // variable to keep track of current bracket number

        // iterating over the string
        for (int i = 0; i < temp.size(); i++) {
            // if opening bracket is encountered
            if (temp[i] == '(') {
                // incrementing the bracket number
                bal++;

                // adding the bracket number to the result vector and stack
                ans.push_back(bal);
                st.push(bal);
            }
            // if closing bracket is encountered
            else if (temp[i] == ')') {
                // adding the top bracket number from the stack to the result vector
                ans.push_back(st.top());
                st.pop();
            }
        }

        return ans; // returning the result vector with assigned bracket numbers
    }
