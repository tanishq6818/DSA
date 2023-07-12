int CountSumConsecutiveNums(int n) 
{
    // Write your code here.
    int count = 0;
    for (int i = 1; i <= n / 2; i++) {
        int sum = i;
        for (int j = i + 1; sum <= n; j++) {
            if (sum == n) {
                count++;
                break;
            }
            sum += j;
        }
    }
    return count;
}
