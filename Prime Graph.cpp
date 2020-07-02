#include<bits/stdc++.h>
 
using namespace std;
 
vector<bool> prime(1e6 + 1, true);
vector<int> deg;
vector<pair<int, int> > edges;
vector<vector<bool> > con;
 
void addEdge(int u, int v){
    edges.emplace_back(u + 1, v + 1);
    deg[u]++;
    deg[v]++;
    con[u][v] = con[v][u] = true;
}
 
int nextPrime(int n){
    for(int i = n; ; i++) if(prime[i]) return i;
}
 
int main(){
    prime[0] = prime[1] = false;
    for(int i = 2; i <= 1e6; i++){
        if(!prime[i]) continue;
        for(int j = i * 2; j <= 1e6; j += i) prime[j] = false;
    }
    int n;
    cin >> n;
    deg.resize(n, 0);
    con.resize(n, vector<bool>(n, false));
    for(int i = 0; i < n; i++) addEdge(i, (i + 1) % n);
    int toAdd = nextPrime(n) - n;
    for(int i = 0; i < toAdd; i++){
        bool found = false;
        for(int u = 0; u < n && !found; u++){
            for(int v = u + 1; v < n && !found; v++){
                if(!con[u][v] && prime[deg[u] + 1] && prime[deg[v] + 1]){
                    addEdge(u, v);
                    found = true;
                }
            }
        }
    }
    cout << edges.size() << endl;
    for(auto e: edges) cout << e.first << " " << e.second << endl;
}