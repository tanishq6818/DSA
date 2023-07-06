//Quick Sort

void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if (low < high) {
            // Find the partitioning index
            int partitionIndex = partition(arr, low, high);
            
            // Recursively sort the elements before and after the partition
            quickSort(arr, low, partitionIndex - 1);
            quickSort(arr, partitionIndex + 1, high);
        }
    }
    int partition (int arr[], int low, int high)
    {
       // Your code here
       int pivot = arr[high]; // Choose the last element as the pivot
        int i = low - 1; // Index of the smaller element
        
        for (int j = low; j <= high - 1; j++) {
            // If the current element is smaller than or equal to the pivot
            if (arr[j] <= pivot) {
                i++; // Increment the index of the smaller element
                swap(arr[i], arr[j]);
            }
        }
        
        swap(arr[i + 1], arr[high]);
        return (i + 1); // Return the index of the pivot
    }
