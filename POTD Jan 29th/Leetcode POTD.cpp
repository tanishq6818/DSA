// Queue to Stacks
class MyQueue {
private:
    std::stack<int> inStack;
    std::stack<int> outStack;

    void transferElements() {
        // Transfer elements from inStack to outStack
        while (!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        inStack.push(x);
    }
    
    int pop() {
        if (outStack.empty()) {
            transferElements();
        }
        
        int front = outStack.top();
        outStack.pop();
        return front;
    }
    
    int peek() {
        if (outStack.empty()) {
            transferElements();
        }
        
        return outStack.top();
    }
    
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};
