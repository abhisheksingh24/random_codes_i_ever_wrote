#include<iostream>
#include<vector>
#include<limits>

using namespace std;

#define INF numeric_limits<int>::max()

struct Edge{
    int src, tgt, w;
};

bool relax(vector<int> &dist, int u, int v, int w){

    cout << "Relaxing " << u << " to " << v << endl;

    if(dist[u] == -INF){
        dist[v] = -INF;
        return true;
    }
    if(dist[u] + w < dist[v]){
        dist[v] = dist[u] + w;
        return true;
    }
    return false;
}

vector<int> findStarts(vector<Edge> edges, int n){
    vector<int> dist;
    for(int i = 0; i < n; i++) dist.push_back(INF);
    dist[0] = 0;

    cout << "Distances from 0: \n";
    for(int i = 0; i < n; i++) cout << "To " << i << " : " <<dist[i] << endl;

    for(int i = 0; i < n-1; i++){
        for(Edge e: edges){
            relax(dist, e.src, e.tgt, e.w);

            cout << "Distances from 0: \n";
            for(int i = 0; i < n; i++) cout << "To " << i << " : " <<dist[i] << endl;

        }
    }
    bool cycle = false;
    for(Edge e: edges){
        if(relax(dist, e.src, e.tgt, e.w)){
            dist[e.tgt] = -INF;
            cycle = true;
        }
    }
    vector<int> res;

    if(!cycle) cout << "No relaxes";

    if(!cycle) return res;
    for(int i = 2; i < n-1; i++){
        for(Edge e: edges){
            relax(dist, e.src, e.tgt, e.w);
        }
    }
    for(int i = 0; i < n; i++){
        if(dist[i]==-INF) res.push_back(i);
    }
    return res;
}

int main(){
    int t, n , m, x, y, w;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<Edge> edges;
        vector<int> startPoints;
        for(int i = 0; i < m; i++){
            cin >> x >> y >> w;
            edges.push_back({x, y, w});
        }

        startPoints = findStarts(edges, n);
        if(startPoints.empty()) cout << "Impossible";
        else for(int star: startPoints) cout << star << " ";
        cout << endl;
    }
}
