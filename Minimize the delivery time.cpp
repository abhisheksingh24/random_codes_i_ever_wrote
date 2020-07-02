#include<bits/stdc++.h>
 
using namespace std;
 
const long long INF = 1e18;
 
vector<vector<pair<int, long long> > > graph;
map<pair<int, int>, int> edge;
 
void dijkstra(int src, int n, vector<int>& prev, vector<long long>& dist){
    dist.clear();
    prev.clear();
    dist.resize(n);
    prev.resize(n);
    priority_queue<pair<long long, int> > Q;
    for(int i = 0; i < n; i++){
        if(i == 0) dist[i] = 0;
        else dist[i] = INF;
        prev[i] = -1;
        Q.push(make_pair(-dist[i], i));
    }
    vector<bool> visited(n, false);
    while(!Q.empty()){
        auto cur = Q.top();
        Q.pop();
        int u = cur.second;
        long long d = -cur.first;
        visited[u] = true;
        for(auto& nb: graph[u]){
            int v = nb.first;
            if(visited[v]) continue;
            long long alt = d + nb.second;
            if(alt < dist[v]){
                dist[v] = alt;
                prev[v] = u;
                Q.push(make_pair(-dist[v], v));
            }
        }
    }
}
 
int main(){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine eee(seed);
    int n, m;
    cin >> n >> m;
    graph.resize(n);
    map<pair<int, int>, long long> weight;
    for(int i = 1; i <= m; i++){
        int x, y, dist;
        cin >> x >> y >> dist;
        x--; y--;
        if(x > y) swap(x, y);
        graph[x].push_back(make_pair(y, dist));
        graph[y].push_back(make_pair(x, dist));
        auto e = make_pair(x, y);
        if(!weight.count(e) || weight[e] > dist){
            edge[e] = i;
            weight[e] = dist;
        };
    }
    for(auto& node: graph) shuffle(node.begin(), node.end(), eee);
    vector<int> prev;
    vector<long long> dist; 
    dijkstra(0, n, prev, dist);
    vector<vector<int> > seqOfSeq;
    long double mn = INF, lst = -1;
    while(dist[n - 1] < INF){
        vector<int> seq = {n - 1};
        while(seq.back() != 0) seq.push_back(prev[seq.back()]);
        seqOfSeq.push_back(seq);
        if(dist[n - 1] / seqOfSeq.size() < mn) lst = seqOfSeq.size(), mn = dist[n - 1] / lst;
        if(seq.size() == 2){
            for(auto& p: graph[0]){
                if(p.first == n - 1){
                    p.second = INF;
                }
            }
        }
        else for(int i = 1; i < seq.size() - 1; i++) graph[seq[i]].clear(); 
        dijkstra(0, n, prev, dist);
    }
    cout << lst << endl;
    for(int i  = 0; i < lst; i++){
        auto s = seqOfSeq[i];
        cout << s.size() - 1;
        for(int i = s.size() - 1; i > 0; i--){
            int u = s[i], v = s[i - 1];
            if(u > v) swap(u, v);
            cout << " " << edge[make_pair(u, v)];
        }
        cout << endl;
    }
}