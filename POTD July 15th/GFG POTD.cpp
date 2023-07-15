// Delete middle element of a stack
void deleteMidUtil(stack<int>& stack, int size, int current, int mid) {
    // Base case: If the current index is equal to mid, skip the middle element
        if (current == mid) {
            stack.pop();
            return;
        }
    
        // Pop the top element and call deleteMidUtil recursively
        int element = stack.top();
        stack.pop();
        deleteMidUtil(stack, size - 1, current + 1, mid);
    
        // Push the popped element back to the stack
        stack.push(element);
    }
    
    void deleteMid(stack<int>& stack, int size) {
        int mid = ceil((size + 1) / 2.0);  // Calculate the index of the middle element
    
        // Call the utility function to delete the middle element and update the stack
        deleteMidUtil(stack, size, 1, mid);
    }
