//Insertion in a Linked List
void insert(Node * ( & head), int n, int pos, int val) {
    // Write your code here
      if (pos < 0 || pos > n) {
        cout << "Invalid position" << endl;
        return;
    }
    
    Node* newNode = new Node(val);
    
    if (pos == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }
    
    Node* current = head;
    for (int i = 0; i < pos - 1; ++i) {
        current = current->next;
    }
    
    newNode->next = current->next;
    current->next = newNode;
}
