Find missing smallest positive element in array
bool visited[n+1] = {false};

    // Mark positive elements in visited array
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0 && arr[i] <= n) {
            visited[arr[i]] = true;
        }
    }

    // Find the smallest missing positive number
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            return i;
        }
    }

    // If all positive numbers are present, return n+1
    return n + 1;
}
