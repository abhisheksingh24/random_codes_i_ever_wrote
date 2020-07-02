#include<bits/stdc++.h>

using namespace std;

const int MAX = 400;
const long long INF = 1e18;

vector<vector<long long> > dp(MAX, vector<long long>(MAX)), sum(MAX, vector<long long>(MAX));

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> A(n);
        for(int& i: A) cin >> i;
        for(int i = 0; i < n; i++) dp[i][i] = 0, sum[i][i] = A[i];
        for(int k = 1; k < n; k++){
            for(int i = 0; i < n; i++){
                int j = (i + k) % n;
                sum[i][j] = A[i] + sum[(i + 1) % n][j];
            }
        }
        for(int k = 1; k < n; k++){
            for(int i = 0; i < n; i++){
                int l = (i + k) % n;
                dp[i][l] = INF;
                for(int j = i; j != l; j = (j + 1) % n){
                    dp[i][l] = min(dp[i][l], dp[i][j] + dp[(j + 1) % n][l]);
                }
                dp[i][l] += sum[i][l];
            }
        } 
        long long res = INF;
        for(int i = 0; i < n; i++) res = min(res, dp[i][(i + n - 1) % n]);
        cout << res << endl;
    }
}