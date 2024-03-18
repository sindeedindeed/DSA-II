#include <math.h>
#include <iostream>
#define ll long long
using namespace std;
int count(ll num){
    int counter=0;
    while(num>0){
        counter++;
        num/=10;
    }
    return counter;
}
ll karatsuba(ll X, ll Y){
    if(X<10 && Y<10)
        return X*Y;
    int size=fmax(count(X), count(Y));
    int n=(int)floor(size/2.0);
    ll p=(ll)pow(10,n);
    ll a=(ll)floor(X/double(p));
    ll b=(ll)X%p;
    ll c=(ll)floor(Y/double(p));
    ll d=(ll)Y%p;
    ll ac=karatsuba(a,c);
    ll bd=karatsuba(b,d);
    ll e=karatsuba(a+b,c+d)-ac-bd;
    return (ll)(pow(10,2*n)*ac+pow(10,n)*e+bd);
}
int main(){
    ll num=karatsuba(1923, 29405);
    cout<<num;
    return 0;
}