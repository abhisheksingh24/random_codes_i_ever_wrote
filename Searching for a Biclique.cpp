#include<bits/stdc++.h>

using namespace std;

bool compare(bitset<2000>& a, bitset<2000>& b){
    return a.count() > b.count();
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<bitset<2000> > graph(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    sort(graph.begin(), graph.end(), compare);
    int l = 0;
    while(l < n && graph[l].count() >= k) l++;
    bool found = false;
    for(int i = 0; i < l && !found; i++){
        for(int j = i + 1; j < l; j++){
            bitset<2000> b = graph[i] & graph[j];
            if(b.count() >= k){
                found = true;
                break;
            }
        }
    }
    if(found) cout << "YES\n";
    else cout << "NO\n"; 
}