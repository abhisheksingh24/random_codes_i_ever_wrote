#include<bits/stdc++.h>

using namespace std;

pair<int, vector<int> > solve(auto& graph, auto& deg){
    const int n = graph.size();
    vector<int> res(n, 1);
    int edge = 0;
    for(int& i: deg) edge += i;
    edge /= 2;
    if(edge % 2 == 0) return make_pair(1, res);
    for(int i = 0; i < n; i++){
        if(deg[i] % 2){
            res[i] = 2;
            return make_pair(2, res);
        }
    }
    for(int i = 0; i < n; i++){
        if(deg[i]){
            res[i] = 2;
            res[graph[i][0]] = 3;
            return make_pair(3, res);
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int> > graph(n);
        vector<int> deg(n);
        while(m--){
            int u, v;
            cin >> u >> v;
            u--; v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
            deg[u]++; deg[v]++;
        }
        auto res = solve(graph, deg);
        cout << res.first << endl;
        for(int& i: res.second) cout << i << " ";
        cout << endl;
    }
}