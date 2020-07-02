#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define MOD 1000000007

vector<int> vec;
vector<vector<long long> > dp;

long long c(int n, int r){
    if(dp[n][r] == -1){ 
        if(n < r) dp[n][r] = 0;
        else if(r==0 || r==n) dp[n][r] = 1;
        //else if(r==1 || r==n-1) dp[n][r] =  n;
        else dp[n][r] = (c(n-1, r) + c(n-1, r-1))%MOD;
    }
    return dp[n][r];
}

int main(){
    int t, n;
    dp.resize(1001);
    for(int i = 0; i < 1001; i++){
        for(int j =0; j < 1001; j++) dp[i].push_back(-1);
    }
    cin >> t;
    while(t--){
        cin >> n;
        vec.clear();
        vec.resize(n);
        for(int &i: vec) cin >> i;
        sort(vec.begin(), vec.end());
        long long res = 0;
        for(int i =0; i < n; i++){
            if(i%2) res = (res + c(n, i))%MOD;
            for(int j = i+1; j < n; j++){
                if(vec[i] == vec[j]) res = (res + c(i + n - j - 1, min(i, n-j-1))) % MOD;
            }
        }
        if(n%2) res = (res+1)%MOD;
        cout << res << endl;
    }
}