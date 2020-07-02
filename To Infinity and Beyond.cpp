#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 1;

long long solve(int l, int r, vector<vector<int> >& vec, int n){
    if(l == r) return l;
    int m = (l + r) / 2;
    int req = INF, mx = 0;
    for(int i = 0; i < n; i++){
        if(vec[i][2] <= m){
            mx = max(mx, vec[i][1]);
            if(vec[i][1] < req) req = INF;
        }
        else if(vec[i][2] > mx) req = min(req, vec[i][1]);
    }
    if(req == INF) return solve(l, m, vec, n);
    return solve(m + 1, r, vec, n);
}

int main(){
    int n;
    cin >> n;
    vector<int> x(n), v(n), e(n);
    for(int& i: x) cin >> i;
    for(int& i: v) cin >> i;
    for(int& i: e) cin >> i;
    vector<vector<int> > vec;
    for(int i = 0; i < n; i++) vec.push_back({x[i], v[i], e[i]});
    sort(vec.begin(), vec.end());
    //for(auto v: vec) {for(auto i: v) cout << i << " "; cout << endl; }
    int mx = solve(0, 1000, vec, n);
    long long val = 0;
    for(int i = 0; i < n; i++) if(vec[i][2] <= mx) val += vec[i][2];
    cout << val << endl;
}