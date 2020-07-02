#include<bits/stdc++.h>

using namespace std;

vector<vector<bool> > dp(1e4, vector<bool>(101, false));

void pre() {
    
}

int main() {
    pre();
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        cout << dp[n][m] << '\n';
    }
}
