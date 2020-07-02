#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9;

vector<vector<int> > adj;
vector<bool> visited;
vector<int> depth;

void init(int n) {
    adj.resize(n);
    visited.resize(n, false);
    depth.resize(n);
}

void solve(int cur, int par, int& res) {
    visited[cur] = true;
    cout << cur << endl;
    if (adj[cur].empty()) {
        res = 0;
        depth[cur] = 0;
        return;
    }
    if (adj[cur].size() == 1 && par != -1) {
        depth[cur] = 0;
        return;
    }
    multiset<int> depths;
    for (int &ch: adj[cur]) if (ch != par) {
        solve(ch, cur, res);
        depths.insert(depth[ch]);
    }
    for (int &ch: adj[cur]) if (ch != par) {
        depths.erase(depths.lower_bound(depth[ch]));
        int dist;
        if (depths.empty()) dist = max(1, depth[ch]);
        else dist = max(depth[ch], 2 + *depths.rbegin());
        res = min(res, dist);
        depths.insert(depth[ch]);
    }
    depth[cur] = (*depths.rbegin()) + 1;
    if (par == -1) {
        int dist = 1 + (*depths.rbegin());
        if (depths.size() >= 2) dist += 1 + (*(++depths.rbegin()));
        res = min(dist, res); 
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    init(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int res = 0;
    for (int i = 0; i < n; i++) if (!visited[i]) {
        int cur = INF;
        cout << "dfs at " << i << endl;
        solve(i, -1, cur);
        res = max(cur, res);
    }
    cout << res << '\n';
}