#include<bits/stdc++.h>

using namespace std;

int main(){
    long long t;
    cin >> t;
    while(t--){
        long long n;
        long long x;
        cin >> n >> x;
        vector<vector<long long> > A(n, vector<long long>(n));
        for(auto& row: A){
            for(auto& cell: row) cin >> cell;
        }
        vector<vector<vector<long long> > > dp(n, vector<vector<long long> >(n, vector<long long>(1e5 + 1)));
        for(long long k = 0; k < A[n - 1][n - 1]; k++) dp[n - 1][n - 1][k] = 0;
        for(long long k = A[n - 1][n - 1]; k <= 1e5; k++) dp[n - 1][n - 1][k] = 1;
        for(long long j = n - 2; j >= 0; j--){
            for(long long k = 0; k < A[n - 1][j]; k++) dp[n - 1][j][k] = 0;
            for(long long k = A[n - 1][j]; k <= 1e5; k++) dp[n - 1][j][k] = dp[n - 1][j + 1][k - A[n - 1][j]];
        }
        for(long long i = n - 2; i >= 0; i--){
            for(long long k = 0; k < A[i][n - 1]; k++) dp[i][n - 1][k] = 0;
            for(long long k = A[i][n - 1]; k <= 1e5; k++) dp[i][n - 1][k] = dp[i + 1][n - 1][k - A[i][n - 1]];
        }
        for(long long i = n - 2; i >= 0; i--){
            for(long long j = n - 2; j >= 0; j--){
                for(long long k = 0; k < A[i][j]; k++) dp[i][j][k] = 0;
                for(long long k = A[i][j]; k <= 1e5; k++) dp[i][j][k] = dp[i + 1][j][k - A[i][j]] + dp[i][j + 1][k - A[i][j]];
            }
        }
        cout << dp[0][0][x] << endl;
    }
}