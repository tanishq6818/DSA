// Given a binary tree with n nodes, find the number of pairs violating the BST property.
// BST has the following properties:-

// Every node is greater than its left child and less than its right child.
// Every node is greater than the maximum value of in its left subtree and less than the minimum value in its right subtree.
// The maximum in the left sub-tree must be less than the minimum in the right subtree.
// Example 1:

// Input : 
// n = 5
// Input tree
    
// Output :
// 5
// Explanation : 
// Pairs violating BST property are:-
// (10,50), 10 should be greater than its left child value.
// (40,30), 40 should be less than its right child value.
// (50,20), (50,30) and (50,40), maximum of left subtree of 10 is 50 greater than 20, 30 and 40 of its right subtree.
// Example 2:

// Input : 
// n = 6
// Input tree

// Output :
// 8
// Explanation :
// There are total 8 Pairs which violation the BST properties.
// Your task :
// You don't have to read input or print anything. Your task is to complete the function pairsViolatingBST() that takes the root of the tree and n as input and returns number of pairs violating BST property.
 
// Expected Time Complexity: O(n*logn)
// Expected Space Complexity: O(n)
 
// Your Task :
// 1 <= n <= 2*104
// -109 <= node->data <= 109


int my_counter = 0;
    int index = 0;

    // p: initial point in the array, say left index
    // q: mid point
    // r: higher range
    // Function to sort and merge two parts of array.
    void merge(int a[], int p, int q, int r) {
        int l = q - p + 1;
        int a1[l];
        int l2 = r - q;
        int a2[l2];

        // Storing elements present in left half in the array a1.
        for (int i = 0; i < l; i++) {
            a1[i] = a[i + p];
        }
        // Storing elements present in right half in the array a2.
        for (int i = 0; i < l2; i++) {
            a2[i] = a[q + i + 1];
        }

        int left = 0, right = 0, k = p;

        // Using two pointers over the two arrays which helps in storing the
        // smaller element and thus merging the array.
        while (left < l && right < l2) {
            // Comparing element of the arrays a1 and a2 at pointers left and
            // right and accordingly storing the smaller element and updating
            // the pointers.
            if (a1[left] <= a2[right]) {
                a[k] = a1[left];
                left++;
            } else {
                a[k] = a2[right];
                right++;
                // Adding the inversions which is the number of elements which
                // are smaller than a2[right] in the a1 array.
                my_counter += (l - left);
            }
            k++;
        }
        // Storing  the remaining elements of left subarray(if there are any)
        // in the array a1.
        while (left < l) {
            a[k++] = a1[left++];
        }
        // Storing the remaining elements of right subarray(if there are any)
        // in the array a2.
        while (right < l2) {

            a[k++] = a2[right++];
        }
    }

    // Function to mergesort the array, which uses divide and conquer algorithm
    // on left and right halves of array for mergesort operation.
    void mergeSort(int a[], int p, int r) {
        if (p < r) {
            int q = (p + r) / 2;
            // Calling recursive function to sort left half of the array.
            mergeSort(a, p, q);

            // Calling recursive function to sort right half of the array.
            mergeSort(a, q + 1, r);

            // Calling merge function which sorts and merges both halves
            // of the array obtained after calling both recursive function.
            merge(a, p, q, r);
        }
    }

    // Function to count inversions in the array.
    int inversionCount(int arr[], int N) {
        mergeSort(arr, 0, N - 1);
        int res = my_counter;
        my_counter = 0;
        // returning the count of inversions in the array.
        return res;
    }

    // Function to traverse the tree in in-order and store the node values in an array
    void inOrderStorage(Node *r, int arr[]) {
        if (r != NULL) {
            // Traverse left subtree
            inOrderStorage(r->left, arr);

            // Store the node value in the array
            arr[index++] = r->data;

            // Traverse right subtree
            inOrderStorage(r->right, arr);
        }
    }

    // Function to count the number of pairs violating BST property
    int pairsViolatingBST(int n, Node *root) {

        int arr[n];
        // Store the in-order traversal of the tree in the array
        inOrderStorage(root, arr);

        return inversionCount(arr, n);
    }
