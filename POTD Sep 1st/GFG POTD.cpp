// Given a Binary Tree of size N, Print the corner nodes ie- the node at the leftmost and rightmost of each level.

// Example 1:

// Input :
//          1
//        /  \
//      2      3
//     / \    / \
//    4   5  6   7    
// Output: 1 2 3 4 7
// Explanation:
// Corners at level 0: 1
// Corners at level 1: 2 3
// Corners at level 2: 4 7
// Example 2:

// Input:

//         10
//       /    \
//      20     30
//     / \  
//    40  60
// Output: 10 20 30 40 60
// Your Task:  
// You dont need to read input. Complete the function printCorner() which takes root node as input parameter and prints the corner nodes separated by spaces. The left corner should be printed before the right for each level starting from level 0.
// Note: Don't print a new line after printing all the corner nodes.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(number of nodes in a level)

// Constraints:
// 1 ≤ N ≤ 10^5

void printCorner(Node *root)
{
    // star node is for keeping track of levels
    queue<Node *> q;

    // pushing root node and star node
    q.push(root);
    q.push(NULL);

    // if isFirst = true then left most node of that level
    // will be printed
    bool isFirst = false;

    // if isOne = true then that level has only one node
    bool isOne = false;

    // last will store right most node of that level
    int last;

    // Do level order traversal of Binary Tree
    while (!q.empty())
    {
        // dequeue the front node from the queue
        Node *temp = q.front();
        q.pop();

        // if isFirst is true, then temp is leftmost node
        if (isFirst)
        {
            cout << temp->data << " ";

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);

            // make isFirst as false and one = 1
            isFirst = false;
            isOne = true;
        }

            // Else if temp is a separator between two levels
        else if (temp == NULL)
        {
            // Insert new separator if there are items in queue
            if (q.size() >= 1)
                q.push(NULL);

            // making isFirst as true because next node will be
            // leftmost node of that level
            isFirst = true;

            // printing last node, only if that level
            // doesn't contain single node otherwise
            // that single node will be printed twice
            if (!isOne)
                cout << last << " ";
        }
        else
        {
            // Store current key as last
            last = temp->data;

            // Here we are making isOne = false to signify
            // that level has more than one node
            isOne = false;
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}
