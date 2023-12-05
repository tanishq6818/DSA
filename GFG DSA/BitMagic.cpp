// 2's Complement representation= 2^n - x      n=no of bits in number x
// x=-1-x
//IN unsigned RIGHT SHIFT OPerator ,for negative numbers,  the leading bits will be filled by 1 instead of 0 (>>>)


//LEFT SHIFT OPERATOR
void checkKthBit(int n){
    if(n & (1<<(k-1))==0){
        cout<<"Bit is Zero";
    }
    else if(n & (1<<(k-1))!=0){
        cout<<"Bit is One";
    }
}

//RIGHT SHIFT OPERATOR
void checkKthBit(int n){
    if((n>>(k-1))&1==0){
        cout<<"Bit is Zero";
    }
    else if((n>>(k-1))&1!=0){
        cout<<"Bit is One";
    }
}
