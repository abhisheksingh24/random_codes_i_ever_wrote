#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> v, m; 
vector<vector<int>> neighbor;
vector<pair<int, ll>> res;

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

void solve(int cur, int parent, ll g){
    g = gcd(g, v[cur]);
    if(neighbor[cur].empty() || (parent != -1 && neighbor[cur].size() == 1)){
        res.emplace_back(cur, m[cur] - gcd(m[cur], g));
        return;
    }
    for(int n: neighbor[cur]) if(n != parent) solve(n, cur, g);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        neighbor.clear();
        res.clear();
        neighbor.resize(n);
        for(int i = 0; i < n-1; ++i){
            int x, y;
            cin >> x >> y;
            neighbor[x-1].push_back(y-1);
            neighbor[y-1].push_back(x-1);
        }
        v.resize(n);
        m.resize(n);
        for(auto& i: v) cin >> i;
        for(auto& i: m) cin >> i;
        solve(0, -1, v[0]);
        sort(res.begin(), res.end());
        for(auto p: res){
            cout << p.second << " ";
        }
        cout << endl;
    }
}