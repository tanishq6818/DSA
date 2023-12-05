int prime(int n){
    if(n==1)    return 0;
    for(int i=2;i<n;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

bool prime2(int n){                             //Best Optimized
    if(n==1)    return false;
    if(n==2 || n==3)    return true;
    if(n%2==0 || n%3==0)    return false;
    for(int i=5;i*i<=n;i+=6){
        if(n%i==0 || n%(i+2)==0){
            return false;
        }
    }
    return true;
}

void primefactors(int n){
    for(int i=2;i<=n;i++){
        if(prime2(i)){
            int x=i;
            while(n%i==0){
                cout<<i<<" ";
                x*=i;
            }
        }
    }
}

void primefactors2(int n){            //Optimized
    if(n<=1)    return;
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            cout<<i;
            n/=i;
        }
    }
    if(n>1){
        cout<<n;
    }
}

void primefactors3(int n){                    //Best Optimization
    if(n<=1)    return;
    while(n%2==0){
        cout<<2<<" ";
        n/=2;
    }
    while(n%3==0){
        cout<<3<<" ";
        n/=3;
    }
    for(int i=5;i*i<=n;i+=6){
        while(n%i==0){
            cout<<i<<" ";
            n/=i;
        }
        while(n%(i+2)==0){
            cout<<i+2<<" ";
            n/=(i+2);
        }
    }
    if(n>3){
        cout<<n<<" ";
    }
}



//SIEVE OF ERATOSTHENES

void SOE(int n){
    //To print all prime numbers less than n
    //By replacing the value of non prime numbers as false using its multiples
    vector<bool> isPrime(n+1,true);
    for(int i=2;i*i<=n;i++){
        if(isPrime[i]){
            for(int j=2*i;j<=n;j+=i){
                isPrime[j]=false;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(isPrime[i]){
            cout<<i<<" ";
            }
        }
    }
}

void SOE2(int n){
    vector<bool> isPrime(n+1,true);
    for(int i=2;i*i<=n;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=n;j+=i){           //Further Optimization
                isPrime[j]=false;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(isPrime[i]){
            cout<<i<<" ";
            }
        }
    }
}

void SOE3(int n){                                //Best optimization with shorter length
    vector<bool> isPrime(n+1,true);
    for(int i=2;i<=n;i++){
        if(isPrime[i]){
            cout<<i<<" ";
            for(int j=i*i;j<=n;j+=i){
                isPrime[i]=false;
            }
        }
    }
}
