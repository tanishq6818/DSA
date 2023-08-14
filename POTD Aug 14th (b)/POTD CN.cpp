// You are given an array, 'ARR', consisting of 'N' integers. You are also given two other integers, 'SUM' and 'MAXVAL. The elements of this array follow a special property that the absolute value of each element is not more than 'MAXVAL. Your task is to determine the minimum number of integers required to be added into the array such that the sum of all the elements of the array becomes equal to 'SUM.

// Note:

// All the new numbers being added to the array must follow the original property of the array.

#include <bits/stdc++.h> 
int findMinNumbers(vector<int> &arr, int sum, int maxVal) {
	// Write your code here.
	int currentSum = 0;
    for (int num : arr) {
        currentSum += num;
    }
    
    int diff = abs(sum - currentSum);
    int minNumbers = (diff + maxVal - 1) / maxVal; // Ceil(diff / maxVal)
    
    return minNumbers;
}
