#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<set<int> > rem(6);
    for(int i = 0; i < 6; i++) for(int j = i; j < 6; j++) rem[i].insert(j), rem[j].insert(i);
    int n, m;
    cin >> n >> m;
    vector<vector<int> > graph(n);
    vector<int> deg(n), too(n, -1);
    while(m--){
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
        deg[u]++; deg[v]++;
    }
    vector<int> order;
    for(int d = 6; d > 0; d--){
        for(int i = 0; i < n; i++){
            if(deg[i] == d) order.push_back(i);
        }
    }
    for(int i = 0; i < n; i++){
        int u = too[order[i]];
        if(u == -1){
            int mn = 0;
            for(int j = 0; j < n; j++){
                if(rem[j].size() >= deg[order[i]]){
                    if(rem[j].size() < rem[mn].size()) mn = j;
                }
                else if(rem[j].size() > rem[mn].size()) mn = j;
            }
            u = mn;
        }
        for(int j: graph[u]){
            if(done[u][v]) continue;
        }
    }
}