#include<bits/stdc++.h>

using namespace std;

set<int> bfs(int cur, vector<set<int> >& graph, vector<bool>& visited){
    set<int> justVisited;
    queue<int> toVisit;
    toVisit.push(cur);
    justVisited.insert(cur);
    while(!toVisit.empty()){
        int now = toVisit.front();
        toVisit.pop();
        if(visited[now]) continue;
        visited[now] = true;
        for(int neigh: graph[now]){
            if(!visited[neigh]){
                toVisit.push(neigh);
                justVisited.insert(neigh);
            }
        }
    }
    return justVisited;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<set<int> > graph(n);
    for(int i = 0; i < m; i++){
        int k;
        cin >> k;
        if(k == 0) continue;
        int x;
        cin >> x;
        x--;
        for(int z = 0; z < k - 1; z++){
            int y;
            cin >> y;
            y--;
            graph[x].insert(y);
            graph[y].insert(x);
        }
    }

/*
    int xx = 0;
    for(auto node: graph){
        cout << xx++ << ": ";
        for(int neigh: node) cout << neigh << " ";
        cout << endl;
    }
    */

    vector<bool> visited(n, false);
    vector<int> cnt(n);
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            set<int> justVisited = bfs(i, graph, visited);
            //for(int jv: justVisited) cout << jv << " "; cout << endl;
            for(int member: justVisited){
                cnt[member] = justVisited.size();
            }
        }
    }
    for(int c: cnt) cout << c << " ";
    cout << endl;
}