
// Reverse a Stack Using Recursion

void insertAtBottom(std::stack<int> &St, int data) {
    if (St.empty()) {
        St.push(data);
    } else {
        int temp = St.top();
        St.pop();
        insertAtBottom(St, data);
        St.push(temp);
    }
}

void Reverse(std::stack<int> &St) {
    if (!St.empty()) {
        int temp = St.top();
        St.pop();
        Reverse(St);
        insertAtBottom(St, temp);
    }
}
