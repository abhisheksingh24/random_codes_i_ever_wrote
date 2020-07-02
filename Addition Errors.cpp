#include<iostream>

using namespace std;

long long power(long long b, long long e){
    if(e==0) return 1;
    if(e%2) return b*power(b*b, e/2);
    return power(b*b, e/2);
}

long long add(long long a, long long b){
    long long res = 0, dig = 0;
    while(a > 0 || b > 0){
        int d1 = a%10, d2 = b%10;
        int d3 = (d1 + d2)%10;  
        res += d3*power(10, dig);
        a/=10; b/=10;
        ++dig;
    }
    return res;
}

int main(){
    int t;
    long long a, b;
    cin >> t;
    while(t--){
        cin >> a>> b;
        cout << (a+b) - add(a, b) << endl; 
    }
}