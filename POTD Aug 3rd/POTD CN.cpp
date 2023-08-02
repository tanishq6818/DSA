// Left Rotate an Array by One
vector<int> rotateArray(vector<int>& arr, int n) {
    if (n <= 1) {
        return arr; // No need to rotate for n <= 1
    }

    int firstElement = arr[0];
    for (int i = 1; i < n; i++) {
        arr[i - 1] = arr[i];
    }

    arr[n - 1] = firstElement;

    return arr;
}
