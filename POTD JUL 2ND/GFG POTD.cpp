// Given a linked list with string data, check whether the combined string formed is palindrome. If the combined string is palindrome then return true otherwise return false.

// Example:

// Input:

// Output : true
// Explanation: As string "abcddcba" is palindrome the function should return true.
// Input:

// Output : false
// Explanation: As string "abcdba" is not palindrome the function should return false.
// Expected Time Complexity:  O(n)
// Expected Auxiliary Space: O(n)

// Constraints:
// 1 <= Node.data.length<= 103
// 1<=list.length<=103

bool compute(Node* head) {
        // Edge case: empty linked list
        if (!head) return true;

        // Traverse the linked list to concatenate strings
        string combinedString;
        Node* current = head;
        while (current) {
            combinedString += current->data;
            current = current->next;
        }

        // Check if combinedString is palindrome
        int left = 0;
        int right = combinedString.length() - 1;
        while (left < right) {
            if (combinedString[left] != combinedString[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
