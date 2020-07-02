#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    vector<int> fact(1e6 + 1), res(1e6 + 1);
    fact[0] = fact[1] = 1;
    for(long long i = 1; i <= 1e6; i++) fact[i] = (i * fact[i - 1]) % MOD;
    res[1] = 1;
    for(int i = 2; i <= 1e6; i++) res[i] = (((1LL * res[i - 1] * fact[i - 1]) % MOD) * i) % MOD; 
    while(t--){
        int n;
        cin >> n;
        cout << res[n] << "\n";
    }
}