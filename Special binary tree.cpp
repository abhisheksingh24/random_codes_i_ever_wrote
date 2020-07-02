/* Mod Inverse from
https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
 */

#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

vector<long long> f(1e6 + 1), fi(1e6 + 1);

int modInverse(int a, int m = MOD){ 
    int m0 = m; 
    int y = 0, x = 1; 
    if (m == 1) return 0; 
    while (a > 1){ 
        int q = a / m; 
        int t = m; 
        m = a % m, a = t; 
        t = y; 
        y = x - q * y; 
        x = t; 
    } 
    if (x < 0) x += m0; 
    return x; 
} 

void pre(){
    f[0] = 1;
    for(int i = 1; i <= 1e6; i++) f[i] = (f[i - 1] * i) % MOD;
    for(int i = 0; i <= 1e6; i++) fi[i] = modInverse(f[i]);
}

int secondlastRow(int n){
    for(int i = 1; ; i *= 2) if(i >= n) return i / 2;
}

int lastRow(int n){
    for(int i = 1; i < n; i *= 2) n -= i;
    return n;
}

long long C(int n, int r){
    return (((f[n] * fi[r]) % MOD) * fi[n - r]) % MOD;
}

int solve(int n){
    int x = secondlastRow(n);
    int y = lastRow(n);
    return (((f[n / 2] * f[n - n / 2]) % MOD) * 2 * ((C(x, y / 2) * C(x, y - y / 2)) % MOD)) % MOD;
}

int main(){
    int t;
    cin >> t;
    pre();
    while(t--){
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
}