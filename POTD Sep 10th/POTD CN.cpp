std::vector<int> addOneToNumber(std::vector<int> arr) {
    int n = arr.size();
    int carry = 1; // Initialize the carry to 1 to add 1 to the number.

    for (int i = n - 1; i >= 0; i--) {
        int sum = arr[i] + carry;
        arr[i] = sum % 10; // Update the current digit.
        carry = sum / 10; // Update the carry for the next iteration.

        // If there's no carry left, we can stop early.
        if (carry == 0) {
            break;
        }
    }

    // If there's still a carry left, we need to insert it as a new digit.
    if (carry > 0) {
        arr.insert(arr.begin(), carry);
    }

    // Remove any leading zeros, but allow a single zero at the end.
    while (!arr.empty() && arr[0] == 0 && arr.size() > 1) {
        arr.erase(arr.begin());
    }

    return arr;
}
