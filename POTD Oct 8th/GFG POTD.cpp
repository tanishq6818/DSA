// Given a linked list sorted in ascending order and an integer called data, insert data in the linked list such that the list remains sorted.

// Example 1:

// Input:
// LinkedList: 25->36->47->58->69->80
// data: 19
// Output: 
// 19 25 36 47 58 69 80
// Explanation:
// After inserting 19 the sorted linked list will look like the one in the output.
// Example 2:

// Input:
// LinkedList: 50->100
// data: 75
// Output: 
// 50 75 100
// Explanation:
// After inserting 75 the sorted linked list will look like the one in the output.
// Your Task:
// The task is to complete the function sortedInsert() which should insert the element in sorted Linked List and return the head of the linked list

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 <= N <= 104
// -99999 <= A[i] <= 99999, for each valid i

class Solution{
  public:
    Node *sortedInsert(Node* head, int data) {
        Node* newNode = new Node(data); // Step 1
        if (!head || head->data >= data) { // If the list is empty or new data is smaller than the head
            newNode->next = head; // Insert at the beginning
            return newNode; // Return the new head
        }
        Node* prev = nullptr;
        Node* current = head;

        // Traverse the list to find the correct position to insert
        while (current && current->data < data) { // Step 3
            prev = current;
            current = current->next;
        }

        // Insert the new node between prev and current
        prev->next = newNode; // Step 4
        newNode->next = current; // Step 5

        return head; // Return the head of the modified linked list
    }
};
