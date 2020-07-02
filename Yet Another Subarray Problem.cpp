#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> A(n);
    for(int& i: A) cin >> i;
    vector<long long> dp(n);
    for(int i = n - 1; i >= 0; i--){
        vector<long long> sums = {0};
        for(int j = i; j < n && j - i + 1 <= m; j++){
            sums.push_back(sums.back() + A[j]);
        }
        if(i + m < n) sums.push_back(sums.back() + dp[i + m]);
        dp[i] = max(0LL, *max_element(sums.begin(), sums.end()) - k);
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
}