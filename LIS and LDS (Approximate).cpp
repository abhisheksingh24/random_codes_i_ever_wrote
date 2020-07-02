#include<iostream>
#include<vector>

using namespace std;

vector<vector<int> > graph;
vector<bool> visited;

int main(){
    int n, m, t, u, v;
    cin >> n >> m >> t;
    graph.resize(n+1);
    visited.resize(n+1, false);
    while(m--){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> path;
    path.push_back(1);
    int last = 1;
    while(true){
        bool found = false;
        for(int i: graph[last]){
            if(visited[i]) continue;
            path.push_back(i);
            last = i;
            visited[i] = true;
            found = true;
            break;
        }
        if(!found) break;
    }
    cout << path.size() << endl;
    for(int i: path) cout << i << " ";
    cout << endl;
}