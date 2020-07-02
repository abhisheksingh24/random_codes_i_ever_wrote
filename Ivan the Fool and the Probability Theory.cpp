#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main(){
    int n, m;
    cin >> n >> m;
    vector<long long> f(max(n, m) + 1);
    f[0] = 1; f[1] = 2;
    for(int i = 2; i < f.size(); i++) f[i] = (f[i - 1] + f[i - 2]) % MOD;
    long long res = 0;
    for(int i = 1; i < min(n, m); i++){
        res += f[max(0, n - i - 2)];
        res %= MOD;
        res += f[max(0, m - i - 2)];
        res %= MOD;
    }
    res += f[abs(n - m)];
    res %= MOD;
    cout << (2 * res) % MOD << endl;
}