// Given two integer array A and B of size N each.
// A sum combination is made by adding one element from array A and another element of array B.
// Return the maximum K valid sum combinations from all the possible sum combinations.

// Note : Output array must be sorted in non-increasing order.

// Example 1:

// Input:
// N = 2
// K = 2
// A [ ] = {3, 2}
// B [ ] = {1, 4}
// Output: {7, 6}
// Explanation: 
// 7 -> (A : 3) + (B : 4)
// 6 -> (A : 2) + (B : 4)
// Example 2:

// Input:
// N = 4
// K = 3
// A [ ] = {1, 4, 2, 3}
// B [ ] = {2, 5, 1, 6}
// Output: {10, 9, 9}
// Explanation: 
// 10 -> (A : 4) + (B : 6)
// 9 -> (A : 4) + (B : 5)
// 9 -> (A : 3) + (B : 6)
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function maxCombinations() which takes the interger N,integer K and two integer arrays A [ ] and B [ ] as parameters and returns the maximum K valid distinct sum combinations .

// Expected Time Complexity: O(Nlog(N))
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 ≤ N ≤  105
// 1 ≤ K ≤  N
// 1 ≤ A [ i ] , B [ i ] ≤ 104

vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        //sorting both arrays in ascending order.
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        vector<int> ans;

        //creating a priority queue to store maximum sums of combinations.
        priority_queue<pair<int, pair<int, int>>> pq;

        //creating a set to store visited combinations.
        set<pair<int, int>> my_set;

        //pushing the maximum sum of combinations obtained from last elements
        //of both arrays along with their indices.
        pq.push(make_pair(A[N - 1] + B[N - 1], make_pair(N - 1, N - 1)));

        //inserting the indices of last elements in set.
        my_set.insert(make_pair(N - 1, N - 1));

        //iterating K times to find K maximum sum combinations.
        for (int count = 0; count < K; count++) {
            //popping the maximum sum from priority queue.
            pair<int, pair<int, int>> temp = pq.top();
            pq.pop();

            //storing the maximum sum in the answer array.
            ans.push_back(temp.first);

            //getting the indices of the elements used to get the maximum sum.
            int i = temp.second.first;
            int j = temp.second.second;

            //checking if it is possible to consider the next element
            //from A array and calculating the sum.
            if (i - 1 >= 0) {
                int sum = A[i - 1] + B[j];

                //creating a pair to store the indices.
                pair<int, int> temp1 = make_pair(i - 1, j);

                //checking if the pair already exists in the set.
                if (my_set.find(temp1) == my_set.end()) {
                    //if not, pushing the sum and indices to priority queue
                    //and inserting the indices in set.
                    pq.push(make_pair(sum, temp1));
                    my_set.insert(temp1);
                }
            }

            //checking if it is possible to consider the next element
            //from B array and calculating the sum.
            if (j - 1 >= 0) {
                int sum = A[i] + B[j - 1];

                //creating a pair to store the indices.
                pair<int, int> temp1 = make_pair(i, j - 1);

                //checking if the pair already exists in the set.
                if (my_set.find(temp1) == my_set.end()) {
                    //if not, pushing the sum and indices to priority queue
                    //and inserting the indices in set.
                    pq.push(make_pair(sum, temp1));
                    my_set.insert(temp1);
                }
            }
        }
        
        //returning the answer array containing the maximum sum combinations.
        return ans;
    }
