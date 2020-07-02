#include<bits/stdc++.h>

using namespace std;

const int INF = 200;

int main(){
    int n;
    cin >> n;
    vector<vector<bool> > adj(n);
    vector<vector<int> > dist(n, vector<int>(n, INF));
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(char c: s) adj[i].push_back(c == '1');
    }
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(adj[i][j]) dist[i][j] = 1;
    for(int i = 0; i < n; i++) dist[i][i] = 0;
    for (int k = 0; k < n; k++)  {  
        for (int i = 0; i < n; i++)          {  
            for (int j = 0; j < n; j++)              {  
                if (dist[i][k] + dist[k][j] < dist[i][j])  
                    dist[i][j] = dist[i][k] + dist[k][j];  
            }  
        }  
    }
    //for(int i = 0; i < n; i++) {for(int j = 0; j < n; j++) cout << adj[i][j] << " " ; cout << endl;}

    //for(int i = 0; i < n; i++) {for(int j = 0; j < n; j++) cout << dist[i][j] << " " ; cout << endl;}
    int m;
    cin >> m;
    vector<int> p(m);
    for(int& i: p){
        cin >> i;
        --i;
    }
    vector<int> res;
    res.push_back(p[0]);
    int lst = 0;
    for(int j = 1; j < m; j++){
        if(j == m - 1){
            res.push_back(p[j]);
            break;   
        }
        if(dist[p[lst]][p[j + 1]] == j + 1 - lst) continue;
        res.push_back(p[j]);
        lst = j;
    }
    cout << res.size() << endl;
    for(int i: res) cout << i + 1 << " ";
    cout << endl;
}