int pow(int a,int b){            //Optimization
    if(b==0)    return 1;
    int tmp=pow(a,b/2);
    tmp*=tmp;
    if(b%2==0){
        return tmp;
    }
    else{
        return a*tmp;
    }
}


//Iterative Power(Binary Exponential)

int IP(int a,int b,int mod){
    int res=1;
    while(n>0){
        if(n&1){
            res*=a%mod;
        }
        res*=res%m;
        n>>=1;
    }
    return res;
}
