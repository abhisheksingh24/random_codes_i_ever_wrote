#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MAX = 5e17;

vector<ll> A;

bool possible(vector<ll>& val, vector<vector<int> >& dp, ll d, int beg, int k) {
    if(k == 0) return beg == val.size();
    if(beg >= val.size()) return false;
    if(dp[beg][k] == -1){
        if(k > val.size() - beg) dp[beg][k] = 0;
        else{
            bool found = false;
            ll s = 0;
            for(int i = beg; i < val.size(); ++i){
                s += val[i];
                if((s & d) == d && possible(val, dp, d, i + 1, k - 1)){
                    found = true;
                    break;
                } 
            }
            if(found) dp[beg][k] = 1;
            else dp[beg][k] = 0;
        }
    }
    return dp[beg][k];
}

ll solve(vector<ll>& val, int k){
    ll d = 1;
    while(d <= MAX) d *= 2; 
    d /= 2;
    ll cur = 0;
    for(; d; d/=2){
        vector<vector<int> > dp(val.size(), vector<int>(k+1, -1));
        if(possible(val, dp, cur + d, 0, k)) cur += d;
    }
    return cur;
}

int main(){
    int n, q;
    cin >> n;
    A.resize(n);
    for(auto& a: A) cin >> a;
    cin >> q;
    for(int i = 0; i < q; ++i){
        int k;
        cin >> k;
        vector<ll> val;
        for(int i = 0; i < n; ++i) {
            int t;
            cin >> t;
            if(t != 0) val.push_back(A[i] * t);
        } 
        cout << solve(val, k) << endl;        
    }
}