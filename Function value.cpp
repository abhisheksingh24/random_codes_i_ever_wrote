#include<bits/stdc++.h>

using namespace std;

vector<vector<long long> > b, T;

long long MOD;

void init(){
    b = {{2}, 
         {3}, 
         {1}, 
         {1}};
    T = {{1, 3, -1, 2},
         {0, 3, 0, 0},
         {0, 2, -1, 2}, 
         {0, 0, 0, 1}};
}

vector<vector<long long> > matMul(vector<vector<long long> > m1, vector<vector<long long> > m2, long long a, long long b, long long c){
    vector<vector<long long> > res(a, vector<long long>(c));
    for(long long i = 0; i < a; i++){
        for(long long j = 0; j < c; j++){
            res[i][j] = 0;
            for(long long k = 0; k < b; k++){
                long long add = (long long)m1[i][k] * m2[k][j];
                long long sign = (add < 0 ? -1 : 1);
                add = sign * (abs(add) % MOD); 
                res[i][j] += add;
                if(res[i][j] < 0) res[i][j] += MOD;
                res[i][j] %= MOD;
            }
        }
    }
    return res;
} 

vector<vector<long long> > idMat(long long n){
    vector<vector<long long> > res(n, vector<long long>(n, 0));
    for(long long i = 0; i < n; i++) res[i][i] = 1;
    return res;
}

vector<vector<long long> > power(vector<vector<long long> > base, long long exp){
    long long n = base.size();
    if(exp == 0) return idMat(n);
    if(exp % 2) return matMul(base, power(matMul(base, base, n, n, n), exp / 2), n, n, n);
    return power(matMul(base, base, n, n, n), exp / 2);
}

long long sum(long long n){
    if(n <= 0) return 0;
    if(n == 1) return 1;
    vector<vector<long long> > res = matMul(power(T, n / 2 - 1), b, 4, 4, 1);
    if(n % 2) return (res[0][0] + res[1][0]) % MOD;
    return res[0][0];
}

int main(){
    init();
    long long t;
    cin >> t >> MOD;
    while(t--){
        long long l, r;
        cin >> l >> r;
        cout << (sum(r) - sum(l - 1) + MOD) % MOD << endl; 
    }
}