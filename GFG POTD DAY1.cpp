//Number of 1's Bits
int setBits(int n) {
        // Write Your Code here
        int c=0;
        while(n>0){
            c+=n&1;
            n>>=1;
        }
        return c;
}
