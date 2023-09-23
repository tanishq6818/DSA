// Given an array A of n positive numbers. The task is to find the first equilibrium point in an array. Equilibrium point in an array is a position such that the sum of elements before it is equal to the sum of elements after it.

// Note: Return equilibrium point in 1-based indexing. Return -1 if no such point exists. 

// Example 1:

// Input: 
// n = 5 
// A[] = {1,3,5,2,2} 
// Output: 
// 3 
// Explanation:  
// equilibrium point is at position 3 as sum of elements before it (1+3) = sum of elements after it (2+2). 
// Example 2:

// Input:
// n = 1
// A[] = {1}
// Output: 
// 1
// Explanation:
// Since there's only element hence its only the equilibrium point.
// Your Task:
// The task is to complete the function equilibriumPoint() which takes the array and n as input parameters and returns the point of equilibrium. 

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= n <= 105
// 1 <= A[i] <= 109
int equilibriumPoint(long long a[], int n) {
    long long totalSum = 0;
    long long leftSum = 0;
    
    // Calculate the total sum of the array
    for (int i = 0; i < n; i++) {
        totalSum += a[i];
    }
    
    // Initialize the right sum
    long long rightSum = totalSum;
    
    for (int i = 0; i < n; i++) {
        // Update the right sum by subtracting the current element
        rightSum -= a[i];
        
        // Check if the left and right sums are equal
        if (leftSum == rightSum) {
            // Return the 1-based index of the equilibrium point
            return i + 1;
        }
        
        // Update the left sum by adding the current element
        leftSum += a[i];
    }
    
    // If no equilibrium point is found, return -1
    return -1;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    long long a[n];
    
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int equilibrium = equilibriumPoint(a, n);
    
    if (equilibrium != -1) {
        cout << "Equilibrium point is at position " << equilibrium << endl;
    } else {
        cout << "No equilibrium point found." << endl;
    }
    
    return 0;
}
This code calculates the equilibrium point in 1-based indexing and returns -1 if no equilibrium point is found. It has a time complexity of O(n) and uses constant auxiliary space, as required.





