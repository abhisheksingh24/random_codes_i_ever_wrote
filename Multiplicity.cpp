#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define MOD 1000000007

int n, mx;
vector<int> a, cur;
vector<vector<int> > divisors;
vector<pair<int, int> > toUpdate;

int solve(int x){
    //cout << x << " : "; for(int i: cur) cout << i << " "; cout << endl;
    if(x == n){
        int res = 0;
        for(int i: cur) res = ((long long)res + i) % MOD;
        return res - 1;
    }
    toUpdate.clear();
    for(int i: divisors[a[x]]){
        toUpdate.emplace_back(i, cur[i-1]);
    }
    for(auto p: toUpdate){
        cur[p.first] = (cur[p.first] + p.second) % MOD;
    }
    return solve(x+1);
}

int main(){
    cin >> n;
    a.resize(n);
    for(int &i: a) cin >> i;
    mx = *max_element(a.begin(), a.end());
    divisors.resize(mx + 1);
    for(int i = 1; i <= min(n,mx); i++){
        for(int j = i; j <= mx; j+=i){
            divisors[j].push_back(i);
        }
    }
    cur.resize(n+1);
    for(int &i: cur) i = 0;
    cur[0] = 1;
    cout << solve(0) << endl;
}