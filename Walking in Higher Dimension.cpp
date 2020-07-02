#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

vector<int> fact(2001);

long long modInverse(long long a) {
    long long m = MOD; 
    long long m0 = m; 
    long long y = 0, x = 1; 
    if (m == 1) return 0; 
    while (a > 1) { 
        long long q = a / m; 
        long long t = m; 
        m = a % m, a = t; 
        t = y; 
        y = x - q * y; 
        x = t; 
    } 
    if (x < 0) x += m0; 
    return x; 
} 

long long factorial(int n){
    if(n == 0) return 1;
    return (n * factorial(n - 1)) % MOD;
}

int main(){
    fact[0] = 1;
    for(long long i = 1; i <= 2000; i++) fact[i] = (i * fact[i - 1])  % MOD;
    int k;
    cin >> k;
    vector<int> x(k);
    int s = 0;
    for(int& i: x){
        cin >> i;
        i--;
        s += i;
    }
    long long res = factorial(s);
    for(int i: x) res = (res * modInverse(fact[i])) % MOD;
    cout << res << endl;
}