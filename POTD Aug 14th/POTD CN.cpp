struct KadaneResult {
    int maxSum;
    int start;
    int end;
};

KadaneResult maxSumSubarray(std::vector<int>& arr) {
    int n = arr.size();
    int maxSum = arr[0];
    int currentSum = arr[0];
    int start = 0;
    int end = 0;
    int tempStart = 0;

    for (int i = 1; i < n; ++i) {
        if (currentSum < 0) {
            currentSum = arr[i];
            tempStart = i;
        } else {
            currentSum += arr[i];
        }

        if (currentSum > maxSum) {
            maxSum = currentSum;
            start = tempStart;
            end = i;
        }
    }

    return {maxSum, start, end};
}

int maxSumRectangle(std::vector<std::vector<int>>& arr, int n, int m) {
    int maxSum = std::numeric_limits<int>::min();

    for (int left = 0; left < m; ++left) {
        std::vector<int> temp(n, 0);
        for (int right = left; right < m; ++right) {
            for (int i = 0; i < n; ++i) {
                temp[i] += arr[i][right];
            }

            KadaneResult kadane = maxSumSubarray(temp);
            if (kadane.maxSum > maxSum) {
                maxSum = kadane.maxSum;
            }
        }
    }

    return maxSum;
}
