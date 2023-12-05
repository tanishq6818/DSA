void printDivisors(int n){
    for(int i=1;i<=n;i++){
        if(n%i==0){
            cout<<i;
        }
    }
}
void printDivisors2(int n){            //Optimized
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            cout<<i;
            if(i!=n/i)  cout<<i;          //To avoid printing perfect square
        }
    }
}

void printDivisors3(int n){              //Best Optimized
    int i;
    for(i=1;i*i<=n;i++){
        if(n%i==0){
            cout<<i;
        }
    }
    for(i>=1;i--){
        if(n%i==0){
            cout<<n/i;
        }
    }
}
