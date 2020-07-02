#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > dp;

int main(){
    int t, n, q;
    string s;
    cin >> t;
    for(int tt = 1; tt <= t; tt++){
        cin >> n >> q;
        cin >> s;
        dp.clear();
        dp.resize(n, vector<int>(26, 0));
        dp[0][s[0] - 'A']++;
        for(int i = 1; i < n; ++i){
            for(int j = 0; j < 26; ++j) dp[i][j] = dp[i - 1][j];
            dp[i][s[i] - 'A']++;
        }
        int res = 0;
        while(q--){
            int l, r;
            cin >> l >> r;
            --l; --r;
            vector<int> cnt;
            if(l == 0) for(int i = 0; i < 26; ++i) cnt.push_back(dp[r][i]);
            else for(int i = 0; i < 26; ++i) cnt.push_back(dp[r][i] - dp[l - 1][i]);
            int odd = 0;
            for(int c: cnt) if(c % 2) ++odd;
            res += (odd <= 1);
        }
        cout << "Case #" << tt << ": " << res << endl;
    }
}