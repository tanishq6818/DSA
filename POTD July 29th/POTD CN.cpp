// k-th node from the end of the linked list Sample Input 1 :
// 2
// 43 6 9 1 5 -1
// 4
// 3 7 -32 8 11 -1
// 5
// Sample Output 1 :
// 6
// 3
// Explanation Of Sample Input 1 :
// First Test Case : 

// The given linked list is: 43->6->9->1->5
// We can clearly see that the 4th element from the last is 6 therefore we return a pointer pointing to the element ‘6’.

// Second Test Case :

// The linked list in this case is 3->7->-32->8->11
// The 5th element from last is the first node of the list therefore we return a pointer pointing to the first node i.e. ‘3’
// Sample Input 2 :
// 1
// 2 26 35 5 -1
// 1
// Sample Output 2 :
// 5


if (head == NULL || k <= 0)
        return NULL;

    node* ptr1 = head;
    node* ptr2 = head;

    // Move ptr2 k nodes ahead of ptr1
    for (int i = 0; i < k; ++i)
    {
        if (ptr2 == NULL) // If k is greater than the size of the list
            return NULL;
        ptr2 = ptr2->next;
    }

    // Move both pointers together until ptr2 reaches the end of the list
    while (ptr2 != NULL)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return ptr1;
