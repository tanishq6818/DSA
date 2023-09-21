// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

 

// Example 1:

// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.
// Example 2:

// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       vector<int>v;
       int i=0,j=0;

       while(i<nums1.size() && j<nums2.size())
       {
           if(nums1[i]>nums2[j])
           {
               v.push_back(nums2[j]);
                j++;
           }
           else
           {
               v.push_back(nums1[i]);
               i++;
           }
       }
       while(i<nums1.size())
       {
            v.push_back(nums1[i]);
               i++;
       }
       while(j<nums2.size())
           {
               v.push_back(nums2[j]);
                j++;
           }
        
        int n=v.size();
        if(n%2!=0)
        return v[n/2];
        return (v[n/2]+v[n/2-1])/2.0;
 }
 

class Solution {
public:
    int p1 = 0, p2 = 0;

    // Get the smaller value between nums1[p1] and nums2[p2] and move the pointer forward.

    int getMin(vector<int>& nums1, vector<int>& nums2) {
        if (p1 < nums1.size() && p2 < nums2.size()) {
            return nums1[p1] < nums2[p2] ? nums1[p1++] : nums2[p2++];
        } else if (p1 < nums1.size()) {
            return nums1[p1++];
        } else if (p2 < nums2.size()) {
            return nums2[p2++];
        } 
        return -1;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = int(nums1.size()), n = int(nums2.size());
        
        if ((m + n) % 2 == 0) {
            for (int i = 0; i < (m + n) / 2 - 1; ++i) {
                int _ = getMin(nums1, nums2);
            }
            return (double)(getMin(nums1, nums2) + getMin(nums1, nums2)) / 2;
        } else {
            for (int i = 0; i < (m + n) / 2; ++i) {
                int _ = getMin(nums1, nums2);
            }
            return getMin(nums1, nums2);
        }
            
        return -1;
    }
};
