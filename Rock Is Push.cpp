#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
 
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<bool> > mat(n, vector<bool>(m));
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) mat[i][j] = (s[j] == 'R');
    }
    vector<vector<vector<long long> > > dp(n, vector<vector<long long> >(m, vector<long long>(2)));
    dp[n - 1][m - 1][0] = (!mat[n - 1][m - 1]);
    dp[n - 1][m - 1][1] = 0;
    dp[n - 1][m - 1][2] = 0;
    for(int i = n - 1; i >= 0; i--){
        if(mat[i][m - 1]){
            for(int ii = i; ii >= 0; ii--) dp[ii][m - 1][0] = dp[ii][m - 1][1] = dp[ii][m - 1][2] = 0;
            break;
        }
        dp[i][m - 1][0] = 1;
        dp[i][m - 1][1] = dp[i][m - 1][2] = 0;
    }
    for(int j = m - 1; j >= 0; j--){
        if(mat[n - 1][j]){
            for(int jj = j; jj >= 0; jj--) dp[n - 1][jj][0] = dp[n - 1][jj][1] = dp[n - 1][jj][2] = 0;
            break;
        }
        dp[n - 1][j][0] = 1;
         dp[n - 1][j][1] = dp[n - 1][j][2] = 0;
    }
    for(int i = n - 2; i >= 0; i--){
        for(int j = m - 2; j >= 0; j--){
            dp[i][j][0] = (dp[i + 1][j][0] + dp[i][j + 1][0]) % MOD;
            if(mat[i][j]) dp[i][j][1] = (dp[i + 1][j][0] + dp[i][j + 1][0]) % MOD;
            else dp[i][j][1] = (dp[i + 1][j][1] + dp[i][j + 1][0]) % MOD;
            if(mat[i][j]) dp[i][j][2] = (dp[i + 1][j][0] + dp[i][j + 1][0]) % MOD;
            else dp[i][j][2] = (dp[i + 1][j][2] + dp[i][j + 1][0]) % MOD;
        }
    }
    cout << dp[0][0][0] << endl;
}