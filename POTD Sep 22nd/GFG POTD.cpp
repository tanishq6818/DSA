//first and last occur of x
vector<int> find(int arr[], int n, int x)
{
    vector<int> result(2, -1); // Initialize the result with -1
    
    // Binary search for the first occurrence of x
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == x)
        {
            result[0] = mid;     // Update the first occurrence index
            right = mid - 1;    // Continue searching in the left half
        }
        else if (arr[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    
    // Reset left and right for binary search of last occurrence
    left = 0;
    right = n - 1;
    
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == x)
        {
            result[1] = mid;     // Update the last occurrence index
            left = mid + 1;      // Continue searching in the right half
        }
        else if (arr[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    
    return result;
}
