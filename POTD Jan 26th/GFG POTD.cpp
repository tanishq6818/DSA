// Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
// Note: Unlike 0/1 knapsack, you are allowed to break the item here. 

// Example 1:

// Input:
// N = 3, W = 50
// value[] = {60,100,120}
// weight[] = {10,20,30}
// Output:
// 240.000000
// Explanation:
// Take the item with value 60 and weight 10, value 100 and weight 20 and split the third item with value 120 and weight 30, to fit it into weight 20. so it becomes (120/30)*20=80, so the total weight becomes 60+100+80.0=240.0
// Thus, total maximum value of item we can have is 240.00 from the given capacity of sack. 
// Example 2:

// Input:
// N = 2, W = 50
// value[] = {60,100}
// weight[] = {10,20}
// Output:
// 160.000000
// Explanation:
// Take both the items completely, without breaking.
// Total maximum value of item we can have is 160.00 from the given capacity of sack.
// Your Task :
// Complete the function fractionalKnapsack() that receives maximum capacity , array of structure/class and size N and returns a double value representing the maximum value in knapsack.
// Note: The details of structure/class is defined in the comments above the given function.

// Expected Time Complexity : O(NlogN)
// Expected Auxilliary Space: O(1)

// Constraints:
// 1 <= N <= 105
// 1 <= W <= 109// Comparator function to sort items based on value-to-weight ratio in descending order.
    static bool compare(Item a, Item b) {
        double ratioA = static_cast<double>(a.value) / a.weight;
        double ratioB = static_cast<double>(b.value) / b.weight;
        return ratioA > ratioB;
    }

    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n) {
        // Sort the items based on value-to-weight ratio in descending order.
        std::sort(arr, arr + n, compare);

        double maxValue = 0.0;

        for (int i = 0; i < n; ++i) {
            // If the entire item can fit, add it to the knapsack.
            if (arr[i].weight <= W) {
                maxValue += arr[i].value;
                W -= arr[i].weight;
            } else {
                // If the item cannot fit entirely, take a fraction of it.
                double fraction = static_cast<double>(W) / arr[i].weight;
                maxValue += (fraction * arr[i].value);
                break; // Knapsack is full, so exit the loop.
            }
        }

        return maxValue;
    }
// 1 <= valuei, weighti <= 104

