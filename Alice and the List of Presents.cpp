#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

long long power(long long b, long long e){
    if(e == 0) return 1;
    b %= MOD;
    long long res = power(b * b, e / 2);
    if(e % 2) return (b * res) % MOD;
    return res;
}

int main(){
    long long n, m;
    cin >> n >> m;
    cout << power((power(2, m) - 1 + MOD) % MOD, n)  << endl;
}