#include<bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 1e9 + 7;

vector<int> fact(1e5 + 1), invFact(1e5 + 1);

int nCr(int n, int r){
    if(r > n) return 0;
    return (((1LL * fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
}

long long power(long long b, long long e){
    if(e == 0) return 1;
    b %= MOD;
    long long res = power(b * b, e / 2);
    if(e % 2) return (b * res) % MOD;
    return res;
}

int modInverse(int a, int m = MOD) { 
    int m0 = m; 
    int y = 0, x = 1; 
    if (m == 1) 
      return 0; 
    while (a > 1)     { 
        int q = a / m; 
        int t = m; 
        m = a % m, a = t; 
        t = y; 
        y = x - q * y; 
        x = t; 
    } 
    if (x < 0) 
       x += m0; 
    return x; 
} 

int32_t main(){
    fact[0] = 1;
    for(int i = 1; i <= 1e5; i++) fact[i] = (1LL * fact[i - 1] * i) % MOD;
    for(int i = 0; i <= 1e5; i++) invFact[i] = modInverse(fact[i]);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), res(n, 0);
        for(int& i: a) cin >> i;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++) res[i] = (res[i] + ((((1LL * a[j] * nCr(j, i)) % MOD) * power(2, n - j - 1)) % MOD)) % MOD;
        }        
        for(int& i: res) cout << i << " ";
        cout << endl;
    }
}