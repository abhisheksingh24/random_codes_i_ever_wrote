#include<bits/stdc++.h>

using namespace std;

int main(){
    const int MOD = 1e9 + 7;
    vector<long long> dp1(1e6 + 1), dp2(1e6 + 1);
    dp1[0] = dp2[0] = 1;
    dp1[1] = dp2[1] = 1;
    dp1[2] = dp2[2] = 2;
    for(int i = 3; i <= 1e6; i++){
        dp1[i] = (dp1[i - 1] + dp1[i - 2]) % MOD;
        dp2[i] = (dp2[i - 1] + dp2[i - 2] + dp1[i - 3]) % MOD;
    }
    int n;
    cin >> n;
    cout << dp2[n] << endl;
}