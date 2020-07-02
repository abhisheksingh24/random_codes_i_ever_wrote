#include<bits/stdc++.h>

using namespace std;

const int INF = 1e6 + 1;

auto dijkstra(const vector<vector<int> >& graph, const int source, const vector<int>& val){
    vector<int> minD(graph.size(), INF);
    vector<bool> visited(graph.size(), false);
    minD[source] = val[source];
    set<pair<int, int> > toVisit;
    toVisit.emplace(val[source], source);

    while(!toVisit.empty()){
        int cur = toVisit.begin() -> second;
        visited[cur] = true;
        toVisit.erase(toVisit.begin());
        for(int nxt: graph[cur]){
            if(!visited[nxt] && max(minD[cur], val[nxt]) < minD[nxt]){
                toVisit.erase({minD[nxt], nxt});
                minD[nxt] = max(minD[cur], val[nxt]);
                toVisit.emplace(minD[nxt], nxt);
            }
        }
    }
    return minD;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, s;
        cin >> n >> m >> s;
        vector<int> val(n);
        vector<vector<int> > graph(n);
        for(int& i: val) cin >> i;
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            u--, v--;
            graph[u].push_back(v);
        }
        for(int i: dijkstra(graph, s - 1, val)) cout << i << " ";
        cout << endl;
    }
}