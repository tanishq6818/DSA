// Heapify function to maintain the heap property.
    void heapify(int arr[], int n, int i)
    {
        int largest = i;      // Initialize largest as root
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        // If left child is larger than root
        if (leftChild < n && arr[leftChild] > arr[largest])
            largest = leftChild;

        // If right child is larger than current largest
        if (rightChild < n && arr[rightChild] > arr[largest])
            largest = rightChild;

        // If largest is not root
        if (largest != i)
        {
            swap(arr[i], arr[largest]);

            // Recursively heapify the affected sub-tree
            heapify(arr, n, largest);
        }
    }
    // Function to build a Heap from the array.
    void buildHeap(int arr[], int n)
    {
        // Index of the last non-leaf node
        int lastNonLeafNode = (n / 2) - 1;

        // Start from the last non-leaf node and heapify each node in reverse order.
        for (int i = lastNonLeafNode; i >= 0; i--)
        {
            heapify(arr, n, i);
        }
    }
    // Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        // Build the max-heap from the array.
        buildHeap(arr, n);

        // One by one, extract an element from the max-heap and place it at the end.
        for (int i = n - 1; i > 0; i--)
        {
            // Swap the root (max element) with the last element
            swap(arr[0], arr[i]);

            // Call heapify on the reduced heap (excluding the sorted elements)
            heapify(arr, i, 0);
        }
    }
