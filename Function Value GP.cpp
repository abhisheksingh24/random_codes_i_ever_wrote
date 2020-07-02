#include<bits/stdc++.h>

using namespace std;

long long MOD;

long long GPSS(long long r, long long n){
    r %= MOD;
    if(n == 0) return 1;
    if(n % 2) return ((1 + r) * GPSS(r * r, (n - 1) / 2)) % MOD;
    return (((r * (1 + r)) % MOD) * GPSS(r * r, n / 2 - 1) + 1) % MOD;
}

int GPS(int a, int r, long long n){
    return (a * GPSS(r, n - 1)) % MOD; 
}

int summ(long long n){
    if(n <= 0) return 0;
    if(n == 1 || n == 2) return 1;
    if(n % 2) return GPS(1, 3, (n + 1) / 2);
    if(n % 4) return (GPS(9, 9, (n - 2) / 4) * 2 + (n - 2) / 2 + 1) % MOD;
    return (GPS(3, 9, n / 4) * 2 + n / 2) % MOD; 
}

int sum(long long n){
    return (summ(n) + summ(n - 1)) % MOD;
}

int main(){
    int t;
    cin >> t >> MOD;
    while(t--){
        long long l, r;
        cin >> l >> r;
        cout << (sum(r) - sum(l - 1) + MOD) % MOD << endl;
    }
}