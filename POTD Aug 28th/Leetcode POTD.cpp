 // Implement Stack using Queues
class MyStack {
private:
    std::queue<int> q1;
    std::queue<int> q2;

public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        
        int poppedElement = q1.front();
        q1.pop();
        
        std::swap(q1, q2);  // Swap the queues to maintain the order
        
        return poppedElement;
    }
    
    int top() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        
        int topElement = q1.front();
        q2.push(topElement);
        q1.pop();
        
        std::swap(q1, q2);  // Swap the queues to maintain the order
        
        return topElement;
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};
