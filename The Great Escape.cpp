#include<iostream>
#include<queue>

using namespace std;

queue<int> toVisit;
bool jumpable[3501][3501], visited[3501];
int parent[3501], dist[3501];

void init(int n){
    for(int i = 1; i <= n; i++){
        visited[i] = false;
        for(int j = 1; j <= n; j++){
            jumpable[i][j] = false;
        }
    }
}

int main(){
    int n, m, a, b, s, t, cur;
    bool found = false;
    cin >> n >> m;
    init(n);
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        jumpable[a][b] = jumpable[b][a] = true;
    }
    cin >> s >> t;
    dist[s] = 0;
    toVisit.push(s);
    visited[s] = true;
    while(!toVisit.empty()){
        cur = toVisit.front();
        toVisit.pop();
        if(cur==t){
            cout << dist[cur] << endl;
            found = true;
            break;
        }
        for(int i = 1; i <= n; i++){
            if(jumpable[cur][i] && !visited[i]){
                toVisit.push(i);
                visited[i] = true;
                parent[i] = cur;
                dist[i] = 1 + dist[cur];
            }
        }
    }
    if(!found) cout << 0 << endl;
}
