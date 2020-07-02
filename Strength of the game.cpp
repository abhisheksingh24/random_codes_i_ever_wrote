#include<bits/stdc++.h>

using namespace std;

const int MAX = 1 << 9, MOD = 1e9 + 7;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> S(n);
    vector<vector<long long> > dp(n, vector<long long>(MAX + 1));
    for(int& i: S) cin >> i;
    for(int j = 0; j <= S[n - 1]; j++) dp[n -1][j] = 1;
    for(int j = S[n - 1] + 1; j <= MAX; j++) dp[n - 1][j] = 0;
    for(int i = n - 2; i >= 0; i--){
        for(int j = 0; j <= MAX; j++){
            dp[i][j] = 0;
            for(int k = 0; k <= S[i]; k++){
                dp[i][j] += dp[i + 1][j ^ k];
                dp[i][j] %= MOD;
            }
        }
    }
    for(int i = 0; i <= m; i++) cout << dp[0][i] << " ";
    cout << endl; 
}