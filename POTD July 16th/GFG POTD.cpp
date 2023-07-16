//Queue Reversal

queue<int> rev(queue<int> q) {
        stack<int> s;
    
        // Push all elements from the queue into the stack
        while (!q.empty()) {
            s.push(q.front());
            q.pop();
        }
    
        // Pop elements from the stack and push them back into the queue
        while (!s.empty()) {
            q.push(s.top());
            s.pop();
        }
    
        return q;
    }
