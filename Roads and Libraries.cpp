#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int> > graph;
vector<bool> visited;

void init(int n){
    visited.resize(n+1);
    visited.clear();
    for(int i = 1; i <= n; i++){
        visited[n] = false;
    }
}

int BFS(int start){
    queue<int> toVisit;
    toVisit.push(start);
    visited[start] = true;
    int res = 1;
    while(!toVisit.empty()){
        int cur = toVisit.front();
        toVisit.pop();
        for(int nbor : graph[cur]){
            if(!visited[nbor]){
                toVisit.push(nbor);
                visited[nbor] = true;
                res++;
            }
        }
    }
    return res;
}

long long solve(int n, int l, int r){
    long long res = (long long)(l)*(long long)(n);
    if(l <= r) return res;
    long long diff = l - r;
    //cout << "Difference = " << diff << endl;
    init(n);
    for(int city = 1; city <= n; city++){
        if(visited[city]) continue;
        int temp = BFS(city);
        res -= diff*(temp-1);
    }
    return res;
}

int main(){
    int q, n, m, l ,r, a, b;
    cin >> q;
    while(q--){
        cin >> n >> m >> l >> r;
        graph.resize(n+1);
        graph.clear();
        while(m--){
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        cout << solve(n, l, r) << endl;
    }
}
