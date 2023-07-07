Given a sorted array of integers of size N and a number X. Find the leftmost index of X in the array arr[].

int leftIndex(int N, int arr[], int X) {
        int low = 0;
        int high = N - 1;
        int leftIndex = -1;
    
        while (low <= high) {
            int mid = low + (high - low) / 2;
    
            if (arr[mid] == X) {
                leftIndex = mid;
                high = mid - 1; // Look for a smaller index towards the left
            } else if (arr[mid] < X) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    
        return leftIndex;
    }
