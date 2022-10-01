#include<bits/stdc++.h>
using namespace std;

int digits(int n){
    int c=0;
    while(n>0){
        c++;
        n/=10;
    }
    return c;
    //O(log(n)) ie number of digits in n
}

int sumOfDigits(int n){
    int sum=0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
    //O(log(n)) ie number of digits in n
}

string decimal2Base(int x,int n){
    string op="";
    while(n>0){
        op+=to_string(n%x);
        n/=x;
    }
    reverse(op.begin(),op.end());
    return op;
    //O(log(n)) ie number of digits in n
}


int isPrime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0)
            return 0;
    }
    return 1;
    //O(n^0.5)
}

void Notsieve(int n){
    for(int i=2;i<=n;i++){
        if(isPrime(i))
            cout<<i<<" ";
    }
    //O(n^1.5)
}

void sieve(int n){
    int primes[n+1];
    for(int i=0;i<=n;i++)   primes[i]=1;
    primes[0]=0;
    primes[1]=0;
    for(int i=2;i*i<=n;i++){
        if(primes[i]==1){
            for(int j=2;j*i<=n;j++)
                primes[j*i]=0;
        }
    }

    for(int i=0;i<=n;i++){
        if(primes[i]==1)
            cout<<i<<" ";
    }

    //O(log(logn))
}

void Factors(int n){
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            cout<<i<<" ";
            if(i*i!=n)
                cout<<n/i<<" ";
        }
        //O(n^0.5)
    }
}

void PrimeFactors(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            int count=0;
            while(n%i==0){
                n/=i;
                count++;
            }
            if(count!=1)
                cout<<i<<"^"<<count<<" ";
            else
                cout<<i<<" ";
        }
    }
    if(n!=1)
        cout<<n;
    //O(nlogn)
}

int gcdo(int divisor,int divident){
    while(divisor!=0){
        int rem=divident%divisor;
        divident=divisor;
        divisor=rem;
    }
    return divident;
}

int gcd(int sor,int dent){
    return sor==0? dent:gcd(dent%sor,sor);
    //O(logb)
}

int extendedgcd(int a,int b,int* x,int* y){
    if(b==0){
        *x=1;
        *y=0;
        return a;
    }
    int x1,y1;
    *x=y1;
    *y=x1-(a/b)*y1;
    return extendedgcd(b,a%b,&x1,&y1);
}


//Modular Multiplicative Inv find x such that ax%m=1 and 0<=x<m
int MMI(int a,int m){
    for(int x=0;x<m;x++)
        if((a*x)%m==1)
            return x;

    return -1;
}

int MMIByExtGCD(int a,int m){
    int x,y;
    int g=extendedgcd(a,m,&x,&y);
    if(g!=1)
        return -1;
    return (x%m + m)%m;
}

int main(){
    int x,y;
    PrimeFactors(6);
}