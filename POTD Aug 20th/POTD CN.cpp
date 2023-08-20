bool compareIntervals(const vector<int> &a, const vector<int> &b) {
    return a[1] < b[1]; // Sort intervals by end time
}

int minimumReschedules(int n, vector<vector<int>> &intervals) {
    int reschedules = 0;
    
    for (int i = 0; i < n; ++i) {
        sort(intervals.begin(), intervals.end(), compareIntervals);

        int lastEnd = intervals[0][1];
        for (int j = 1; j < intervals.size(); ++j) {
            if (intervals[j][0] < lastEnd) {
                reschedules++;
            } else {
                lastEnd = intervals[j][1];
            }
        }

        intervals.clear(); // Clear intervals for the next test case
    }

    return reschedules;
}
