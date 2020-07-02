#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > to1, to2;
vector<vector<set<int> > > visited;

int h1, h2;

void init1(int n, int m){
    to1.clear();
    to1.resize(n+1, vector<int>(m+1, -1));
}

void init2(int k, int m){
    to2.clear();
    to2.resize(k+1, vector<int>(m+1, -1));
}

bool isMirror(int u, set<int> v, int m){
    for(auto i: visited[u]) if(i == v) return true;
    visited[u].push_back(v);
    if(u == h1) for(int i: v) if(i != h2) return false;
    for(int i = 1; i <= m; i++){
        int x = to1[u][i];
        if(x == -1){
            for(int vi: v) if(to2[vi][i] != -1) return false;
            continue;
        }
        set<int> y;
        for(int vi: v){
            int vf = to2[vi][i];
            if(vf == -1) return false;
            y.insert(to2[vi][i]);  
        }
        if(!isMirror(x, y, m)) return false;
    }
    return true;
}

int main(){
    int t, n, k, m, e, f, a, b, l;
    cin >> t;
    visited.resize(101);
    while(t--){
        cin >> m;
        cin >> n >> e >> h1;
        init1(n, m);
        for(int i = 0; i < e; i++){
            cin >> a >> b >> l;
            to1[a][l] = b;
        }
        cin >> k >> f >> h2;
        init2(k, m);
        for(int i = 0; i < f; i++){
            cin >> a >> b >> l;
            to2[a][l] = b;
        }
        visited.clear();
        visited.resize(n+1, vector<set<int> >(k+1));
        set<int> temp; temp.insert(1);
        if(isMirror(1, temp, m)) cout << "YES\n";
        else cout << "NO\n";
    }
}