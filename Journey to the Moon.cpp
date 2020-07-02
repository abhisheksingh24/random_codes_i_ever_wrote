
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int> > graph;
vector<bool> visited;

void init(int n){
    visited.resize(n);
    visited.clear();
    for(int i = 0; i < n; i++){
        visited[i] = false;
    }
}

long long BFS(int start){
    queue<int> toVisit;
    toVisit.push(start);
    visited[start] = true;
    long long res = 1;
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

long long solve(int n){
    init(n);
    long long total = 0, res = 0;
    for(int c = 0; c < n; c++){
        if(visited[c]) continue;
        long long temp = BFS(c);
        res += temp*total;
        total+=temp;
    }
    return res;
}

int main(){
    int n, p, a, b;
    cin >> n >> p;
    graph.resize(n+1);
    graph.clear();
    while(p--){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cout << solve(n) << endl;
}
