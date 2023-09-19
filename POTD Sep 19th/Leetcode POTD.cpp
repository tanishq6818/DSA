int findDuplicate(vector<int>& arr) {
        // Find the intersection point of the slow and fast.
        int slow = arr[0];
        int fast = arr[0];
        do {
            slow = arr[slow];
            fast = arr[arr[fast]];
        } while (slow != fast);
        // Find the "entrance" to the cycle.
        int ptr1 = arr[0];
        int ptr2 = slow;
        while (ptr1 != ptr2) {
            ptr1 = arr[ptr1];
            ptr2 = arr[ptr2];
        }
        return ptr1;
}
