#include<bits/stdc++.h>

using namespace std;

#define REP(i,n) for (int i = 0; i < n; i++)
typedef long long ll;
typedef vector<vector<ll> > matrix;
const ll MOD = 1000000007;
const int K = 5;

matrix T{{0, 1, 0, 0, 0}, 
        {0, 0, 1, 0, 0},
        {3, 0, 1, 2, 0},
        {0, 0, 0, 1, 1}, 
        {0, 0, 0, 0, 1}};

matrix mul(matrix A, matrix B){
    matrix C(K, vector<ll>(K));
    REP(i, K) REP(j, K) REP(k, K)
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

matrix pow(matrix A, int p){
    if (p == 1) return A;
    if (p % 2) return mul(A, pow(A, p-1));
    matrix X = pow(A, p/2);
    return mul(X, X);
}

int main(){
    int q, t0, t1, t2, y;
    cin >> q;
    while(q--){
        cin >> t0 >> t1 >> t2 >> y;
        vector<ll> F0{t0, t1, t2, 3, 1};
        matrix Tres = pow(T, y);
        ll res = 0;
        REP(i, K) res = (res + Tres[0][i] * F0[i]) % MOD;
        cout << res << endl;
    }
}