// Remove duplicates from an unsorted linked list

Node * removeDuplicates( Node *head) 
    {
     // your code goes here
     if (head == nullptr)
            return nullptr;

        unordered_set<int> seen;
        Node *current = head;
        Node *prev = nullptr;

        while (current != nullptr)
        {
            if (seen.find(current->data) != seen.end())
            {
                // Duplicate found, remove the node
                prev->next = current->next;
                delete current;
                current = prev->next;
            }
            else
            {
                // New element, add to the set and move to the next node
                seen.insert(current->data);
                prev = current;
                current = current->next;
            }
        }

        return head;
    }
