#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

vector<long long> fact;

void fillfact(long long n){
    fact.resize(n + 1);
    fact[0] = 1; 
    for(long long i = 1; i <= n; i++) fact[i] = (i * fact[i - 1]) % MOD;
}

long long power(long long base, long long exp){
    base %= MOD;
    if(exp == 0) return 1;
    if(exp % 2) return (base * power(base * base, exp / 2)) % MOD;
    return power(base * base, exp / 2);
}

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

long long ways(long long a, long long b, long long n, long long h){
    if(a == b){
        if(a * n != h) return 0;
        return modInverse(fact[n]);
    }
    else{
        if(a < b) swap(a, b);
        if(h - b * n < 0) return 0;
        if((h - b * n) % (a - b)) return 0;
        long long x = (h - b * n) / (a - b);
        if(x > n) return 0;
        long long y = n - x;
        return ((long long) modInverse(fact[x]) * modInverse(fact[y])) % MOD;
    }
}

int main(){
    long long n, h1, h2, a, b, c;
    cin >> n >> h1 >> h2 >> a >> b >> c;
    if(a == b && a== c){
        if(a * n == h2 - h1) cout << 1 << endl;
        else cout << 0 << endl;
        return 0;
    }
    if(a == b) swap(a, c);
    else if(b != c) swap(a, b);
    fillfact(n);
    long long res = 0;
    for(long long i = 0; i <= n; i++){
        long long cur = fact[n];
        cur *= modInverse(fact[i]);
        cur %= MOD;
        cur *= ways(b, c, n - i, h2 - h1 - i * a);
        cur %= MOD;
        res += cur;
        res %= MOD;
    }
    cout << res << endl;
}