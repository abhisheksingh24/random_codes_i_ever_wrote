#include<bits/stdc++.h>

using namespace std;

const long long two = 5e8 + 4, MOD = 1e9 + 7;

long long power(long long b, long long exp){
    b %= MOD;
    if(exp == 0) return 1;
    long long res = power(b * b, exp / 2);
    if(exp % 2) return (res * b) % MOD;
    return res;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        if(n == 0){
            cout << 0 << " " << 0 << endl;
            continue;
        }
        cout << (power(2, n) * two - 1) % MOD << " " << (power(2, n) * two) % MOD << endl;    
    }
}