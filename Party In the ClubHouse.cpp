#include<bits/stdc++.h>

using namespace std;

#define int long long

string temp;

struct LCA {
    vector<int> height, euler, first, segtree;
    vector<bool> visited;
    int n;

    LCA(vector<vector<int>> &adj, int root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(adj, root);
        int m = euler.size();
        segtree.resize(m * 4);
        build(1, 0, m - 1);
    }

    void dfs(vector<vector<int>> &adj, int node, int h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(adj, to, h + 1);
                euler.push_back(node);
            }
        }
    }

    void build(int node, int b, int e) {
        if (b == e) {
            segtree[node] = euler[b];
        } else {
            int mid = (b + e) / 2;
            build(node << 1, b, mid);
            build(node << 1 | 1, mid + 1, e);
            int l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }

    int query(int node, int b, int e, int L, int R) {
        if (b > R || e < L)
            return -1;
        if (b >= L && e <= R)
            return segtree[node];
        int mid = (b + e) >> 1;

        int left = query(node << 1, b, mid, L, R);
        int right = query(node << 1 | 1, mid + 1, e, L, R);
        if (left == -1) return right;
        if (right == -1) return left;
        return height[left] < height[right] ? left : right;
    }

    int lca(int u, int v) {
        int left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }
};

void dfs(int cur, int par, int d, auto& depth, auto& adj){
    depth[cur] = d;
    for(int& ch: adj[cur]) if(ch != par) dfs(ch, cur, d + 1, depth, adj);
}

int32_t main(){
    int t;
    cin >> t;
    getline(cin, temp);
    while(t--){
        int n, q;
        cin >> n >> q;
        getline(cin, temp);
        vector<vector<int> > adj(n);
        vector<int> depth(n);
        for(int i = 0; i < n - 1; i++){
            int x, y;
            cin >> x >> y;
            getline(cin, temp);
            x--; y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        LCA L(adj);
        dfs(0, -1, 0, depth, adj);
        while(q--){
            int x, y, S, H;
            cin >> x >> y >> S >> H;
            getline(cin, temp);
            x--; y--;
            int l = L.lca(x, y);
            int d1 = depth[x] - depth[l];
            int d2 = depth[y] - depth[l];
            if((d1 * (d1 + 1)) / 2 > S || (d2 * (d2 + 1)) / 2 > H){
                cout << -1 << endl;
                continue;
            }
            int dd1 = depth[x];
            int dd2 = depth[y];
            int rem = S + H - (dd1 * (dd1 + 1)) / 2 - (dd2 * (dd2 + 1)) / 2;
            if(rem < 0) cout << -1 << endl;
            else cout << rem << endl;
        }
    }
}