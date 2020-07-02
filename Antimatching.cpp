#include<iostream>
#include<vector>
#include<utility>

using namespace std;

bool cycle(vector<vector<int> > neigh, int n){
    for(int i = 1; i <= n; i++){
        for(int fnb: neigh[i]){
            for(int snb: neigh[fnb]){
                for(int tnb: neigh[snb]){
                    if(tnb == i) return true;
                }
            }
        }
    }
    return false;
}

int main(){
    int t, n, m, x, y;
    cin >> t;
    while(t--){
        vector<pair<int, int> > edges;
        vector<vector<int> > neigh;
        vector<int> degree;
        cin >> n >> m;
        neigh.resize(n+1);
        for(int i =0 ; i <= n; i++) degree.push_back(0);
        for(int i = 0; i < m; i++){
            cin >> x >> y;
            edges.push_back(make_pair(x, y));
            degree[x]++;
            degree[y]++;
            neigh[x].push_back(y);
            neigh[y].push_back(x);
        }
        int maxDeg = 0;
        for(int d: degree) if(d > maxDeg) maxDeg = d;
        if(cycle(neigh, n)) maxDeg = max(3, maxDeg);
        cout << maxDeg << endl;
    }
}