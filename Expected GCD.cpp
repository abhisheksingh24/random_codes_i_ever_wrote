#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > factor(2e5 + 1);
vector<int> sumFact(2e5 + 1, 0), factorial(2e5 + 1), invFact(2e5 + 1), res(2e5 + 1);

const int MOD = 1e9 + 7;

int modInverse(int a, int m = MOD) { 
    int m0 = m; 
    int y = 0, x = 1; 
    if (m == 1) return 0; 
    while (a > 1) { 
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
    for(int i = 1; i <= 2e5; i++){
        for(int j = 2 * i; j <= 2e5; j += i){
            factor[j].push_back(i);
            sumFact[j] += i;
        }
        factor[i].push_back(i);
    }
    factorial[0] = factorial[1] = 1;
    invFact[0] = invFact[1] = 1;
    for(long long i = 2; i <= 2e5; i++){
        factorial[i] = (i * factorial[i - 1]) % MOD;
        invFact[i] = modInverse(factorial[i]);
    }
}

int C(int n, int r){
    if(n < r) return 0;
    return (((1LL * factorial[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
}

int main(){
    pre();

    //for(int i: factor[93312]) cout << i << " "; cout << endl;
    //int mx = 0; for(auto& v: factor) mx = max(mx, (int)v.size()); cout << mx << endl;
    int q, k;
    cin >> q >> k;
    long long cur = 0;
    for(int i = 0; i < k; i++) res[i] = 0;
    for(int n = 1; n <= 5; n++){
        //cout << n << "! = " << factorial[n] << " " << invFact[n] << endl;
        //for(int r = 0; r <= n; r++) cout << n << ", " << r << " : " << C(n, r) << endl;
    }
    for(long long i = k; i <= 2e5; i++){
        //cout << "\ni = " << i << endl;
        for(int j: factor[i]){
            //cout << "j = " <<  j << endl;

            if(i / j < k) break;
            int ways = C(i / j, k);
            int oldWays = C((i - 1) / j, k);
            int newWays = ways - oldWays;
            //cout << i/j << " " << k << " : " << ways << ", " << (i - 1) / j << " : " << oldWays << endl;
            //cout << "cur = " << cur << endl; 
            cur = (cur + ((1LL * (j - sumFact[j]) * newWays) % MOD)) % MOD; 
        }
        //cout << i << " : " << cur << " / " << C(i, k) << endl; 
        res[i] = (cur * modInverse(C(i, k))) % MOD;
    }
    while(q--){
        int n;
        cin >> n;
        cout << res[n] << endl;
    }
}