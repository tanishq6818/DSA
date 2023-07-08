//Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        //Your code here
        unordered_set<int> seen;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int complement = -arr[i] - arr[j];
    
                if (seen.count(complement))
                    return true;
            }
    
            seen.insert(arr[i]);
        }
    
        return false;
    }


// Explamation:

// The findTriplets function takes an array (arr) and its size (n) as input and returns a boolean value indicating whether triplets with a zero sum exist in the array.

// unordered_set<int> seen;: Create an unordered set called seen to store the elements encountered so far.

// Outer loop (for (int i = 0; i < n; ++i)): Iterate over each element in the array.

// Inner loop (for (int j = i + 1; j < n; ++j)): Iterate over the remaining elements after the current element (arr[i]) in the array.

// Calculate the complement: int complement = -arr[i] - arr[j];. The complement is the negative sum of the current two elements, arr[i] and arr[j].

// Check if the complement exists in the seen set: if (seen.count(complement)) return true;. If the complement is found in the set, it means we have found a triplet with a zero sum. In that case, we return true from the function.

// Insert the current element (arr[i]) into the seen set: seen.insert(arr[i]);. This allows us to consider this element as part of future triplets.

// If no triplet with a zero sum is found, we reach the end of the function and return false.
