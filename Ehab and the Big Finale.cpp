#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > graph;
vector<int> mx;

void fillMax(int cur, int par = -1){
    mx[cur] = 1;
    for(int ch: graph[cur]){
        if(ch == par) continue;
        fillMax(ch, cur);
        mx[cur] = max(mx[cur], 1 +mx[ch]);
    }
}

int query(char typ, int cur){
    cout << typ << " " << cur + 1 << endl;
    int res;
    cin >> res;
    if(typ == 's') --res;
    return res;
}

int solve(int cur, int par = -1, int d = -1){
    if(d == -1) d = query('d', cur);
    if(d == 0) return cur;
    if(d == 1) return query('s', cur);
    vector<int> valid;
    for(int ch: graph[cur]){
        if(ch == par) continue;
        if(mx[ch] >= d) valid.push_back(ch);
    }  
    if(valid.size() > 1) return solve(query('s', cur), cur, d - 1);
    return solve(valid[0], cur, d - 1);
}

int main(){
    int n;
    cin >> n;
    graph.resize(n);
    mx.resize(n);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    fillMax(0);
    int x = solve(0);
    cout << "! " << x + 1 << endl;
}