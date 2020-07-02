#include<bits/stdc++.h>

using namespace std;

const int inv4 = 41666667, MOD = 1e9 + 7;

vector<vector<int> > fact(1e5 + 1);

long long power(long long base, int exp){
    base %= MOD;
    if(exp == 0) return 1;
    if(exp % 2) return (base * power(base * base, exp / 2)) % MOD;
    return power(base * base, exp / 2);
}

int main(){
    for(int i = 1; i <= 1e5; i++){
        for(int j = 2 * i; j <= 1e5; j += i) fact[j].push_back(i);
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        long long res = 0;
        for(int i = 1; i <= n; i++){
            long long cur;
            cur = n / i;
            cur %= MOD;
            cur *= (n / i - 1);
            cur %= MOD;
            cur *= (n / i - 2);
            cur %= MOD;
            cur *= (n / i - 3);
            cur %= MOD;
            cur *= inv4;
            cur %= MOD;
            //cout << "i = " << i << " comb = " << cur << endl;
            res += (power(i, 4) * cur) % MOD;
            res %= MOD;
            for(int f: fact[i]){
                res -= (power(f, 4) * cur) % MOD;
                res += MOD;
                res %= MOD;
            }
        }
        cout << res << endl;
    }
}