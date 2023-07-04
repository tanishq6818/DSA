//MAX TWO ELEMENT SUM

int oneIteration(vector<int> A)
{
    // Write your code here.   
    int max1 = INT_MIN;
    int max2 = INT_MIN;

    for (int i = 0; i < A.size(); i++) {
        if (A[i] > max1) {
            max2 = max1;
            max1 = A[i];
        } else if (A[i] > max2) {
            max2 = A[i];
        }
    }

    return max1 + max2;
}
