int toggleKBits(int n, int k) {
    // Write your code here.
    // Create a mask with 'k' bits set to 1
    int mask = (1 << k) - 1;
    
    // Toggle the bits using XOR (^) with the mask
    return n ^ mask;
}
