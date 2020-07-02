#include<bits/stdc++.h>

using namespace std;

vector<int> bfs(int n, vector<vector<int> >& graph, vector<bool>& visited){
    queue<int> toVisit;
    vector<int> prev(n, -1);
    toVisit.push(0);
    visited[0] = true;
    while(prev[n - 1] == -1 && !toVisit.empty()){
        int cur = toVisit.front();
        //cout << cur << endl;
        toVisit.pop();
        for(int& nxt: graph[cur]){
            if(visited[nxt]) continue;
            visited[nxt] = true;
            prev[nxt] = cur;
            toVisit.push(nxt);
        }
    }
    if(prev[n - 1] == -1) return {};
    vector<int> res = {n - 1};
    while(res.back() != 0) res.push_back(prev[res.back()]);
    return res;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int> > graph(n);
    map<pair<int, int>, int> edge;
    map<pair<int, int>, long long> weight;
    for(int i = 0; i < m; i++){
        int u, v, dist;
        cin >> u >> v >> dist;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
        if(u > v) swap(u, v);
        auto e = make_pair(u, v);
        if(!weight.count(e) || weight[e] > dist){
            edge[e] = i + 1;
            weight[e] = dist;
        }
    }
    for(auto& node: graph) random_shuffle(node.begin(), node.end());
    vector<vector<int> > res;
    vector<bool> visited(n, false);
    vector<int> visitList;
    vector<int> s = bfs(n, graph, visited);
    while(res.size() < 10 && !s.empty()){
        res.push_back(s);
        visited.clear();
        visited.resize(n, false);
        if(s.size() == 2){
            for(auto it = graph[0].begin(); it != graph[0].end(); ){
                if(*it == n - 1) it = graph[0].erase(it);
                else ++it;
            } 
        }
        for(int& i: s) if(i != 0 && i != n - 1) visitList.push_back(i);
        for(int& u: visitList) visited[u] = true;
        //for(int& i: s) cout << i << " "; cout << endl;
        s = bfs(n, graph, visited);
    }
    cout << res.size() << endl;
    for(auto seq: res){
        cout << seq.size() - 1;
        for(int i = seq.size() - 1; i > 0; i--){
            int u = seq[i], v = seq[i - 1];
            if(u > v) swap(u, v);
            cout << " " << edge[make_pair(u, v)];
        }
        cout << endl;
    }
}