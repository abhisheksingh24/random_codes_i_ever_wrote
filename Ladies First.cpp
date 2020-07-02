#include<bits/stdc++.h>

using namespace std;

const long long LIM = 1e18;
const int MOD = 1e9 + 7;

vector<long long> dp;

void pre(){
    long long cur = 2;
    dp.push_back(2);
    while(cur <= LIM){
        dp.push_back((dp.back()*dp.back())%MOD);
        cur *= 2;
    }
}

int power(long long b){
    if(b==0) return 1;
    int i = 0, p = 1;
    while(p*2 <= b) p*=2, ++i;
    return (dp[i]*power(b-p)) % MOD;
}

int solve(long long n){
    return ((n%MOD)*power(n-1))%MOD;
}

int main(){
    int t;
    long long n;
    cin >> t;
    pre();
    cout << dp.size() << endl;
    while(t--){
        cin >> n;
        cout << solve(n) << endl;
    }
}