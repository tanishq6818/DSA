// 2's Complement representation= 2^n - x      n=no of bits in number x
// x=-1-x
//IN unsigned RIGHT SHIFT OPerator ,for negative numbers,  the leading bits will be filled by 1 instead of 0 (>>>)

//Checking for the Kth Bit

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


//Counting of the Bits

int countSet(int n){
    int count=0;
    while(n>0){
        count+=(n&1);
        n>>=1;
    }
}

//Look Up table method for numbers range from 0 to 255(DP) 
//It splits the 32 bits in the chunk of 8 bits

int table[256];
void initialize(){
    table[0]=0;
    for(int i=1;i<256;i++){
        table[i]=(i&1 )+ table[i/2];
    }
}
int countBits(int n)
{
    int res=table[n & 0xff];            //0xff denotes the value of Last 8 bits
    n>>=8;
    res+=table[n & 0xff];
    n>>=8;
    res+=table[n & 0xff];
    n>>=8;
    res+=table[n & 0xff];
    return res;
}



//check Power of 2

void checkPowerof2(int n){
    if(n==0){
        return;
    }
    while(n!=1){
        if(n%2!=0)  {
            cout<<"Not a Power of 2";
            break;}
        n/=2;
    }
    cout<<"Power Of 2";
}

bool chkPowerof2(int n){                //Optimized solution
    if(n==0){
        return false;
    }
    return n&(n-1)==0;
}



//Find Odd Occuring Number

int odd(int n,int arr[]){
    int res=0;
    for(int i=0;i<n;i++){
        res^=arr[i];
    }
    return res;
}


int missing(int n,int arr[]){
    int res=0;
    for(int i=1;i<=n;i++){
        res^=i;
    }
    for(int i=0;i<n;i++){
        res^=arr[i];
    }
    return res;
}



//Two odd occurring elements

void twoodd(int n,int arr[]){
    int xorw=0,x,y;
    for(int i=0;i<n;i++){
        xorw^=arr[i];
    }
    int st=xorw & ~(xorw-1);
    for(int i=0;i<n;i++){
        if(st & arr[i] != 0){
            x=x^arr[i];
        }
        else{
            y^=arr[i];
        }
    }
}

//PowerSet using Bit
void powerset(string str){
    int n=str.length();
    int powersize=pow(2,n);
    for(int counter=0; counter<powersize;counter++){
        for(int j=0;j<n;j++){
            if(counter & (1<<(j)) != 0){
                cout<<str[i]<<" ";
            }
        }
        cout<<endl;
    }
}
