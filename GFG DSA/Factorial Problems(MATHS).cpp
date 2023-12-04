int fact(int n){    //Optimized Version
    if(n==0)    return 1;
    return n*fact(n-1);
}

int trailingzeros(int n){
    int factorial=fact(n);
    int res=0;
    while(factorial%10==0){
        res++;
        factorial/=10;
    }
}

int trailingzeros2(int n){  //Optimized version
    int res=0;
    for(int i=5;i<=n;i*=5){
        res+=n/i;
    }
    return res;
}
