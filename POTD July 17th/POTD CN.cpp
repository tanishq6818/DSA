// Check whether K-th bit is set or not
bool isKthBitSet(int n, int k) {
    int mask = 1 << (k - 1);
    return (n & mask) != 0;
}
