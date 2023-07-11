int minSubarraySum(int arr[], int n, int k) 
{
    // Write your code here 
    if (k > n)
        return -1;

    int minSum = INT_MAX;
    int currentSum = 0;

    // Calculate the sum of the first k elements
    for (int i = 0; i < k; i++)
        currentSum += arr[i];

    minSum = currentSum;

    // Calculate the sum of remaining subarrays of size k
    for (int i = k; i < n; i++) {
        currentSum += arr[i] - arr[i - k]; // Update the sum by adding the next element and removing the first element of the previous subarray
        minSum = std::min(minSum, currentSum);
    }

    return minSum;
}
