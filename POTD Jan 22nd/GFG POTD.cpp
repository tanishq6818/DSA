// Given a Binary tree and a sum S, print all the paths, starting from root, that sums upto the given sum. Path not necessarily end on a leaf node.

// Example 1:

// Input : 
// sum = 8
// Input tree
//          1
//        /   \
//      20      3
//            /    \
//          4       15   
//         /  \     /  \
//        6    7   8    9      

// Output :
// 1 3 4
// Explanation : 
// Sum of path 1, 3, 4 = 8.
// Example 2:

// Input : 
// sum = 38
// Input tree
//           10
//        /     \
//      28       13
//            /     \
//          14       15
//         /   \     /  \
//        21   22   23   24
// Output :
// 10 28
// 10 13 15  
// Explanation :
// Sum of path 10, 28 = 38 and
// Sum of path 10, 13, 15 = 38.
// Your task :
// You don't have to read input or print anything. Your task is to complete the function printPaths() that takes the root of the tree and sum as input and returns a vector of vectors containing the paths that lead to the sum.
 
// Expected Time Complexity: O(N)
// Expected Space Complexity: O(N2)
 
// Your Task :
// 1 <= N <= 2*103
// -103 <= sum, Node.key <= 103


// /*// A Tree node
// struct Node
// {
// 	int key;
// 	struct Node *left, *right;
// };*/

class Solution
{
    public:
        void printPathsUtil(Node* curr_node, int sum,
                     int sum_so_far, vector<int> &path , vector<vector<int>> &ans)
            {
            	if (curr_node == NULL)
            		return;
            
            	// add the current node's value
            	sum_so_far += curr_node->key;
            
            	// add the value to path
            	path.push_back(curr_node->key);
            
            	// print the required path
            	if (sum_so_far == sum )
            	{
            		ans.push_back(path);
            	}
            
            	// if left child exists
            	if (curr_node->left != NULL)
            		printPathsUtil(curr_node->left, sum, sum_so_far, path, ans);
            
            	// if right child exists
            	if (curr_node->right != NULL)
            		printPathsUtil(curr_node->right, sum, sum_so_far, path, ans);
            
            
            	// Remove last element from path
            	// and move back to parent
            	path.pop_back();
            }

    public:
        vector<vector<int>> printPaths(Node *root, int sum)
            {
            	vector<int> path;
            	vector<vector<int>> ans;
            	printPathsUtil(root, sum, 0, path, ans);
            	return ans;
            }
};
