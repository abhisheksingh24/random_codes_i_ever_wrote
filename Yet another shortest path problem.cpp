#include<bits/stdc++.h>

using namespace std;

const int INF = 1e6;
vector<map<int, set<int> > > graph;
vector<int> dist;

set<int> inter(auto& a, auto& b){
    set<int> res;
    if(a.size() < b.size()){
        for(auto& i: a) if(b.count(i)) res.insert(i);
    }
    else for(auto& i: b) if(a.count(i)) res.insert(i);
    return res;
}

set<int> uni(auto& a, auto& b){
    set<int> res;
    for(auto& i: a) res.insert(i);
    for(auto& i: b) res.insert(i);
    return res;
}

void dijkstra(int s){
    const int n = graph.size(); 
    dist.assign(n, INF);
    vector<bool> visited(n, false);
    priority_queue<tuple<int, int, set<int> > >  visit;
    visit.emplace(0, s, set<int>());
    dist[s] = 0;
    while(!visit.empty()){
        int v;
        set<int> se;
        tie(ignore, v, se) = visit.top();
        visit.pop();
        if(visited[v]) continue;
        visited[v] = true;
        for(auto& neigh: graph[v]){
            int u = neigh.first;
            set<int> cols = neigh.second;
            int altDist = dist[v];
            set<int> altCols = inter(cols, se);
            if(altCols.empty()) altDist++, altCols = cols;
            if(altDist < dist[u]){
                dist[u] = altDist;
                visit.emplace(-altDist, u, altCols);
            }
            else if(altDist == dist[u]){
                visit.emplace(-altDist, u, uni(altCols, se));
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    graph.resize(n);
    while(m--){
        int u, v, c;
        cin >> u >> v >> c;
        u--; v--;
        if(u > v) swap(u, v);
        graph[u][v].insert(c);
        graph[v][u].insert(c);
    }
    int s, t;
    cin >> s >> t;
    s--; t--;
    dijkstra(s);
    cout << max(dist[t] - 1, 0) << endl;
}