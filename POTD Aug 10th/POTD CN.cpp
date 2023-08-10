string stringReverse(string S) {
    int left = 0;
    int right = S.length() - 1;

    while (left < right) {
        swap(S[left], S[right]);
        left++;
        right--;
    }

    return S;
}
