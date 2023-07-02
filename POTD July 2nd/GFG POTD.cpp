//GFG POTD 
/*Given two numbers X and Y, and a range [L, R] where 1 <= L <= R <= 31. You have to copy the set bits of 'Y' in the range L to R in 'X'. Return this modified X.

Note: Range count will be from Right to Left & start from 1.*/


def setSetBit(self, X, Y, L, R):
        # code here
        for i in range(L, R+1):
            mask = 1 << (i-1)  # Create a mask with a single set bit at position i
            if Y & mask:  # Check if the corresponding bit in Y is set
                X = X | mask  # Set the bit in X
        return X
