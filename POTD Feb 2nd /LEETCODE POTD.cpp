// An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

// Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

 

// Example 1:

// Input: low = 100, high = 300
// Output: [123,234]
// Example 2:

// Input: low = 1000, high = 13000
// Output: [1234,2345,3456,4567,5678,6789,12345]
 

// Constraints:

// 10 <= low <= high <= 10^9

std::vector<int> sequentialDigits(int low, int high) {
    std::vector<int> result;
    
    for (int i = 1; i <= 9; ++i) {
        int num = i;
        int nextDigit = i;
        
        while (num <= high && nextDigit < 10) {
            if (num >= low) {
                result.push_back(num);
            }
            
            nextDigit++;
            num = num * 10 + nextDigit;
        }
    }
    
    std::sort(result.begin(), result.end());  // Sort the result vector
    
    return result;
}
