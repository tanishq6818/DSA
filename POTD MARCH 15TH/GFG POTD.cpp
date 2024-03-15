// You are given a Linked list of size n. The list is in alternating ascending and descending orders. Sort the given linked list in non-decreasing order.

// Example 1:

// Input:
// n = 6
// LinkedList = 1->9->2->8->3->7
// Output: 1 2 3 7 8 9
// Explanation: 
// After sorting the given list will be 1->2->3->7->8->9.
// Example 2:

// Input:
// n = 5
// LinkedList = 13->99->21->80->50
// Output: 13 21 50 80 99
// Explanation:
// After sorting the given list will be 13->21->50->80->99.
// Your Task:
// You do not need to read input or print anything. The task is to complete the function sort() which should sort the linked list of size n in non-decreasing order. 

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= Number of nodes <= 100
// 0 <= Values of the elements in linked list <= 103

void reverselist(Node *&head)
    {
    	Node* prev = NULL, *curr = head, *next;
    	
    	while (curr)
    	{
    		next = curr->next;   // storing value for next node
    		curr->next = prev;   // linking node to previous node
    		prev = curr;         // updating value of prev node
    		curr = next;         // updating value of current node
    	}
    	head = prev;
    }
    
    Node *mergelist(Node *head1, Node *head2)
    {
    	if (!head1) return head2;  // base cases
    	if (!head2) return head1;  // base cases
    	
    	Node *temp = NULL;
    	
    	if (head1->data < head2->data)
    	{
    		temp = head1;     // picking the lower value
    		head1->next = mergelist(head1->next, head2);
    		// recursively merging the remaining list
    	}
    	else
    	{
    		temp = head2;     // picking the lower value
    		head2->next = mergelist(head1, head2->next);
    		// recursively merging the remaining list
    	}
    	return temp;
    }
    
    void splitList(Node *head, Node **Ahead, Node **Dhead)
    {
    	*Ahead = new Node(0);
    	    // first node for the list (will be discarded later)
    	*Dhead = new Node(0);
    	    // first node for the list (will be discarded later)
    	
    	Node *ascn = *Ahead;
    	Node *dscn = *Dhead;
    	Node *curr = head;
    	
    	while (curr)
    	{
    	    // first element goes to ascending list
    		ascn->next = curr;
    		ascn = ascn->next;
    		curr = curr->next;
    		
    		if (curr)
    		{
    		    // second element goes to descending list
    			dscn->next = curr;
    			dscn = dscn->next;
    			curr = curr->next;
    		}
    	}
    	ascn->next = NULL;
    	dscn->next = NULL;
    	*Ahead = (*Ahead)->next;   // discarding first element
    	*Dhead = (*Dhead)->next;   // discarding first element
    }
    
    void sort(Node **head)
    {
    	Node *Ahead, *Dhead;
    	splitList(*head, &Ahead, &Dhead);
    	// function to split the list
    	// Ahead stores the elements with even index (0,2,4...)
    	// Dhead stores elements with odd index
    	
    	reverselist(Dhead);
    	// reversing list with head Dhead since it contains
    	// elements in decreasing order
    	
    	*head = mergelist(Ahead, Dhead);
    	// merging back both lists in increasing order
    }
