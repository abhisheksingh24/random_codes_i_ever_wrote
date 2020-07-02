#include<iostream>
#include<queue>

using namespace std;

struct path{
    int to, magNum;
};

vector<path> links[100001];
bool visited[100001];

void findPath(vector<path> nodes, int from, int toLook, int n){
    int cur, l;
    for(int i = 0; i < n; i++) visited[i] = false;
    queue<int> q;
    q.push(from);
    visited[from] = true;
    while(q.empty()){
        cur = q.front();
        q.pop();
        l = links[cur].size();
        for(int i = 0; i < l; i++){
            if(links[cur][i].to == toLook)
        }
    }
}

int main(){
    path temp;
    vector<path> nodes;
    int t, n, u, v, c, k;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n-1; i++){
            cin >> u >> v >> c;
            links[u].push_back({v,c});
        }
        cin >> m;
        for(int i = 0; i < m; i++){
            cin >> u >> v >> k;
            findPath(nodes, u, v, n);
        }
    }
}
