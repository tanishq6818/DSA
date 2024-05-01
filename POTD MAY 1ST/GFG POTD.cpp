// Given a singly linked list having n nodes containing english alphabets ('a'-'z'). Rearrange the linked list in such a way that all the vowels come before the consonants while maintaining the order of their arrival. 

// Example 1:

// Input:
// n = 9
// linked list: a -> b -> c -> d -> e -> f -> g -> h -> i 
// Output: 
// a -> e -> i -> b -> c -> d -> f -> g -> h
// Explanation: 
// After rearranging the input linked list according to the condition the resultant linked list will be as shown in output.
// Example 2:

// Input:
// n = 8
// linked list: a -> b -> a -> b -> d -> e -> e -> d 
// Output: 
// a -> a -> e -> e -> b -> b -> d -> d
// Explanation: 
// After rearranging the input linked list according to the condition the resultant linked list will be as shown in output.
// Your Task:
// Your task is to complete the function arrangeCV(), which takes head of linked list and arranges the list in such a way that all the vowels come before the consonants while maintaining the order of their arrival and returns the head of the updated linked list.

// Expected Time Complexity :  O(n)
// Expected Auxiliary Space :  O(1)

// Constraints:
// 1 <= n <= 104
// 'a' <= elements of linked list <= 'z'

class Solution {
public:
    Node* arrangeCV(Node* head) {
        if (!head || !head->next) return head;  // If the list is empty or has only one node

        // Initialize pointers for vowel and consonant lists
        Node *vowelHead = nullptr, *vowelTail = nullptr;
        Node *consonantHead = nullptr, *consonantTail = nullptr;

        Node *current = head;
        while (current != nullptr) {
            if (isVowel(current->data)) {
                // Add to vowel list
                if (!vowelHead) {
                    vowelHead = vowelTail = current;
                } else {
                    vowelTail->next = current;
                    vowelTail = current;
                }
            } else {
                // Add to consonant list
                if (!consonantHead) {
                    consonantHead = consonantTail = current;
                } else {
                    consonantTail->next = current;
                    consonantTail = current;
                }
            }
            current = current->next;
        }

        // Check for non-empty vowel and consonant lists and combine them
        if (vowelTail) {
            vowelTail->next = consonantHead;  // Link the end of vowel list to the head of consonant list
        }
        if (consonantTail) {
            consonantTail->next = nullptr;  // Mark the end of the list
        }

        return vowelHead ? vowelHead : consonantHead;  // If vowelHead is null, the list is all consonants
    }

    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }};
