#include<bits/stdc++.h>

using namespace std;

void dfs(int cur, int par, vector<long long>& maxSpend, vector<int>& toll, vector<vector<int> >& graph){
    maxSpend[cur] = 2LL * toll[cur];
    if(par != -1) maxSpend[cur] += maxSpend[par];
    long long mx = -1;
    for(int child: graph[cur]){
        if(child == par) continue;
        dfs(child, cur, maxSpend, toll, graph);
        mx = max(mx, maxSpend[child]);
    }
    maxSpend[cur] = mx;
}


long long solve(int cur, int par, vector<long long>& maxSpend, long long k, long long spent, vector<vector<int> >& graph){
    
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x, k;
        cin >> n >> x >> k;
        x--;
        vector<int> toll(n);
        vector<vector<int> > graph(n);
        vector<int> maxSpend(n), maxSpend(n), rem(n);
        for(int& i: toll) cin >> i;
        for(int i = 0; i < n - 1; i++){
            int u, v;
            cin >> u >> v;
            u--; v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs(x, -1, maxSpend, toll, graph);
        cout << solve(x, -1, maxSpen, k, 0, graph) << endl;
    }
}