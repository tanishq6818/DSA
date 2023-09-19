unsigned int getFirstSetBit(int n)
{
    if (n == 0)
        return 0;

    int position = 1;
    int mask = 1;

    while ((n & mask) == 0)
    {
        // Left shift the mask to check the next bit
        mask <<= 1;
        position++;
    }

    return position;
}
