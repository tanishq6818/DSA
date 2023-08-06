// Given a string S. The task is to find all permutations (need not be different) of a given string.

// Example 1:

// Input:
// S = AAA
// Output: AAA AAA AAA AAA AAA AAA
// Explanation: There are total 6 permutations, as given in the output.
// Example 2:

// Input:
// S = ABSG
// Output: ABGS ABSG AGBS AGSB ASBG ASGB
// BAGS BASG BGAS BGSA BSAG BSGA GABS
// GASB GBAS GBSA GSAB GSBA SABG SAGB
// SBAG SBGA SGAB SGBA
// Explanation: There are total 24 permutations, as given in the output.
// Your Task:
// This is a function problem. You only need to complete the function permutation that takes S as parameter and returns the list of permutations in lexicographically increasing order. The newline is automatically added by driver code.

void permutations(string str, int i, int n,vector<string>&v)
    {
        // base condition
        if (i == n - 1)
        {
            v.push_back(str);
            return;
        }
    
        // process each character of the remaining string
        for (int j = i; j < n; j++)
        {
            // swap character at index i with current character
            swap(str[i], str[j]);       // STL swap() used
    
            // recurse for string [i+1, n-1]
            permutations(str, i + 1, n,v);
    
            // backtrack (restore the string to its original state)
            swap(str[i], str[j]);
        }
    }
    
    
    vector<string> permutation(string S)
    {
        vector<string> v;
        permutations(S,0,S.length(),v);
        sort(v.begin(),v.end());
        return v;
    }
