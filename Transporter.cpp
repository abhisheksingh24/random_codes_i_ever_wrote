#include<bits/stdc++.h>

using namespace std;

long long round(long long w){
    return ((w + 5) / 10) * 10;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<long long> w(n), pre(n);
        vector<vector<long long> > dp(n, vector<long long>(k + 1));
        for(auto& i: w) cin >> i;
        pre[0] = w[0];
        for(int i = 1; i < n; i++) pre[i] = pre[i - 1] + w[i];
        for(int i = 0; i < n; i++) dp[i][0] = 0;
        for(int i = 1; i <= k; i++){
            for(int j = 0; j < n; j++){
                long long mx = round(pre[j]);
                for(long long jj = j - 1, wt = w[j]; jj >= 0; wt += w[jj], --jj){
                    mx = max(mx, round(wt) + dp[jj][i - 1]);
                }
                dp[j][i] = mx;
            }
        }
        cout << dp[n - 1][k] << endl;
    }
}