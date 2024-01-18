// A gallery with plants is divided into n parts, numbered 0, 1, 2, 3, ..., n-1. There are provisions for attaching water sprinklers in every division. A sprinkler with range x at division i can water all divisions from i-x to i+x.

// Given an array gallery[] consisting of n integers, where gallery[i] is the range of the sprinkler at partition i (a power of -1 indicates no sprinkler attached), return the minimum number of sprinklers that need to be turned on to water the entire gallery. If there is no possible way to water the full length using the given sprinklers, print -1.

// Example 1:

// Input:
// n = 6
// gallery[] = {-1, 2, 2, -1, 0, 0}
// Output:
// 2
// Explanation: 
// Sprinklers at index 2 and 5
// can water the full gallery, span of
// sprinkler at index 2 = [0,4] and span
// of sprinkler at index 5 = [5,5].
// Example 2:

// Input:
// n = 9
// gallery[ ] = {2, 3, 4, -1, 2, 0, 0, -1, 0}
// Output:
// -1
// Explanation: 
// No sprinkler can throw water
// at index 7. Hence all plants cannot be
// watered.
// Example 3:

// Input:
// n = 9
// gallery[ ] = {2, 3, 4, -1, 0, 0, 0, 0, 0}
// Output:
// 3
// Explanation: 
// Sprinkler at indexes 2, 7 and
// 8 together can water all plants.
// Your task:
// You do not have to take any input or print anything. Your task is to complete the function min_sprinklers() which takes the array gallery[ ] and the integer n as input parameters and returns the minimum number of sprinklers that need to be turned on to water the entire gallery.

// Expected Time Complexity: O( nlog(n) )
// Expected Auxiliary Space: O( n )

// Constraints:
// 1 ≤ n ≤ 105
// gallery[i] ≤ 50



class Solution{
    public:
    //Function to find the minimum number of sprinklers required.
    int min_sprinklers(int gallery[], int n)
    {
        //creating a vector of pairs to store the range of each sprinkler.
        vector<pair<int,int>> sprinklers;
        
        //iterating over the gallery array.
        for(int i=0; i<n; i++)
        {
            //checking if the gallery at current index is not -1.
            if(gallery[i] > -1)
            {
                //adding the range of each sprinkler to the vector.
                sprinklers.push_back( pair<int,int> ( i-gallery[i], i+gallery[i] ) );
            }
        }
        
        //sorting the sprinklers based on their starting range.
        sort(sprinklers.begin(), sprinklers.end());
        
        //initializing target, sprinklers_on, and i.
        int target=0, sprinklers_on=0, i=0;
        
        //looping until target is less than n.
        while(target<n)
        {
            //checking if i has reached the end of the sprinklers vector
            //or the starting range of next sprinkler is greater than the target.
            if(i==sprinklers.size() || sprinklers[i].first>target)
            {
                //returning -1 if above condition is true.
                return -1;
            }
            
            //initializing max_range with the ending range of current sprinkler.
            int max_range = sprinklers[i].second;
            
            //looping until i+1 is within the range of sprinklers vector
            //and the starting range of next sprinkler is less than or equal to target.
            while( i+1<sprinklers.size() && sprinklers[i+1].first<=target )
            {
                //updating i and max_range if above condition is true.
                i++;
                max_range = max( max_range,  sprinklers[i].second );
            }
            
            //checking if the maximum range is less than target
            //which means no sprinkle can cover the current target point.
            if(max_range<target)
            {
                //returning -1 if above condition is true.
                return -1;
            }
            
            //incrementing the count of sprinklers and updating target and i.
            sprinklers_on++;
            target = max_range +1;
            i++;
        }
        
        //returning the minimum number of sprinklers required.
        return sprinklers_on;
    }
};
