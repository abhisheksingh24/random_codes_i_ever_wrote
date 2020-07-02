/*https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/ */

#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

long long power(long long b, int e){
    if(e == 0) return 1;
    b %= MOD;
    long long res = power(b * b, e / 2);
    if(e % 2) return (b * res) % MOD;
    return res;
}

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

int numOfOnes(int n, int i){
    int x = (2 << i);
    n++;
    int res = ((n / x) * x) / 2;
    n -= (n / x) * x;
    n -= x / 2;
    n = max(0, n);
    return res + n;
}

auto unity(int n){
    vector<vector<int> > res(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) res[i][i] = 1;
    return res;
}

auto matMul(vector<vector<int> > a, vector<vector<int> > b){
    int x = a.size();
    int y = a[0].size();
    int z = b[0].size();
    vector<vector<int> > res(x, vector<int>(z, 0));
    for(int i = 0; i < x; i++){
        for(int j = 0; j < z; j++){
            for(int k = 0; k < y; k++){
                res[i][j] += ((long long)a[i][k] * b[k][j]) % MOD;
                res[i][j] %= MOD; 
            }
        }
    }
    return res;
}

void matMulFast(auto& a, auto& b){
    int x, y, z, l, m;
    x = ((long long)a[0][0] * b[0][0]) % MOD;
    y = (((long long)a[0][0] * b[0][2]) % MOD + ((long long)a[0][2] * b[2][2]) % MOD) % MOD;
    z = ((long long)a[1][0] * b[0][0]) % MOD;
    l = (((long long)a[1][0] * b[0][2]) % MOD + ((long long)a[1][2] * b[2][2]) % MOD) % MOD;
    m = ((long long)a[2][2] * b[2][2]) % MOD;
    a[0][0] = x;
    a[0][2] = y;
    a[1][0] = z;
    a[1][2] = l;
    a[2][2] = m;    
}

int findCount(int n, int k, int x, int f0){
    if(k == 0) return f0;
    //cout << "f0 = " << f0 << endl;
    int f1 = f0 * (n + 1 - x) + (1 - f0) * x;
    vector<vector<int> > base = {{f1},
                                 {f0},
                                 {n+1}};
    int a = n + 1 - 2 * x;
    vector<vector<int> > T = {{a, 0, x},
                              {1, 0, 0},
                              {0, 0, n+1}};
    vector<vector<int> > res = unity(3);                              
    k--;
    while(k){
        if(k & 1) matMulFast(res, T);
        k >>= 1;
        matMulFast(T, T);
    }
    return matMul(res, base)[0][0]; 
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k, s;
        cin >> n >> k >> s;
        long long num = 0;
        for(int i = 0; (1 << i) <= n; i++){
            int x = numOfOnes(n, i);
            long long val = (1 << i);
            int cnt = findCount(n, k, x, (int)(bool)(s & val));
            //cout << i << " : " << val << " " << cnt << endl;
            num += (val * cnt) % MOD;
            num %= MOD;
        }
        long long p = power(n + 1, k);
        for(int i = 0; (1 << i) <= s; i++){
            long long val = (1 << i);
            if((s & val) && val > n) num = (num + (val * p) % MOD) % MOD;
        }
        cout << (num * modInverse(p)) % MOD << endl;
    }
}