#include<bits/stdc++.h>

using namespace std;

vector<int> A;
vector<vector<int> > adj, child;
vector<vector<long long> > dp;

long long maxPath(int x, int type){
    if(child[x].empty()){
        if(type == 2) return A[x];
        return max(0, A[x]);
    }
    if(dp[x][type] != -1) return dp[x][type];
    if(type == 0){
        long long a = 0, b = 0;
        for(int ch: child[x]){
            a = max(a, maxPath(ch, 0));
            b = max(b, maxPath(ch, 1));
        }
        a += A[x];
        dp[x][type] = max(a, b);
    }
    else if(type == 1){
        long long a = 0, b = 0;
        for(int ch: child[x]){
            a = max(a, maxPath(ch, 1));
            b = max(b, maxPath(ch, 2));
        }
        b += A[x];
        dp[x][type] = max(a, b);
    }
    else{
        long long a = 0;
        for(int ch: child[x]){
            a = max(a, maxPath(ch, 2));
        }
        dp[x][type] = a + A[x];
    }
    return dp[x][type];
}

long long maxAt(int x){
    if(child[x].empty()) return max(0, A[x]);
    long long a, b, z1 = 0, z2 = 0, nz1 = 0, nz2 = 0, nz = 0;
    vector<int> id;
    for(int ch: child[x]){
        long long m = maxPath(ch, 1);
        if(m > z1){
            swap(z1, z2);
            z1 = m;
        }
        else if(m > z2) z2 = m;
    }
    for(int ch: child[x]){
        long long m = maxPath(ch, 2);
        if(m > nz1){
            swap(nz1, nz2);
            nz1 = m;
            id = {ch};
        }
        else if(m == nz1){
            id.push_back(ch);
        }
        else if(m > nz2) nz2 = m;
    }
    a = z1 + z2;
    if(id.size() > 1){
        for(int ch: child[x]){
            nz = max(nz, maxPath(ch, 0));
        }    
    }
    else if(id.empty()) nz = 0;
    else{
        for(int ch: child[x]){
            if(ch == id[0]) continue;
            nz = max(nz, maxPath(ch, 0));
        }
    }
    long long m = 0;
    for(int i: id) m = max(m, maxPath(i, 0));
    b = max(nz1 + nz, m + nz2);
    return max(a, b + A[x]);
}

void dfs(int cur, int par){
    for(int i: adj[cur]){
        if(i == par) continue;
        child[cur].push_back(i);
        dfs(i, cur);
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        adj.clear();
        child.clear();
        A.clear();
        dp.clear();
        dp.resize(n, vector<long long>(3, -1));
        adj.resize(n);
        A.resize(n);
        child.resize(n);
        for(int& i: A) cin >> i;
        for(int i = 0; i < n - 1; i++){
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0, -1);
        //cout << "done" << endl;
        long long res = 0;
        for(int i = 0; i < n; i++) res = max(res, maxPath(i, 0));
        //for(int i = 0; i < n; i++) cout << maxPath(i, 0) << " "; cout << endl;
        //for(int i = 0; i < n; i++) cout << maxAt(i) << " "; cout << endl;
        for(int i = 0; i < n; i++) res = max(res, maxAt(i));

        cout << res << endl;
    }
}