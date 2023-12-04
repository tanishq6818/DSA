//Greatest Common Divisor(GCD)
int gcd(int a,int b){
    int res=min(a,b);
    while(res>0){
        if(a%res==0 && b%res==0){
            break;
        }
        res--;
    }
    return res;
}

int gcd2(int a,int b){  //Euclidean Algorithm 
    while(a!=b){
        if(a>b){
            a=a-b;
        }
        else{
            b=b-a;
        }
    }
    return a;
}

int gcd3(int a,int b){  //GCD OPTIMIZED VERSION
    if(b==0){
        return a;
    }
    else
        return gcd(b,a%b);
}

//LCM

int lcm(int a,int b){
    int res=max(a,b);
    while(true){
        if(res%a==0 && res%b==0){
            break;
        }
        res++;
    }
    return res;
}

int lcm2(int a,int b){              //Optimized Version OF lcm and hcf/GCD
    return (a*b)/gcd3(b,a%b);        //Formula: a*b=lcm(a,b) * gcd(a,b)
}
