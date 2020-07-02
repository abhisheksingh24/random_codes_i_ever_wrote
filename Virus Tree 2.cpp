#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

    vector<long long> fact(1e5 + 1);


int modInverse(int a, int m) 
{ 
    int m0 = m; 
    int y = 0, x = 1; 
  
    if (m == 1) 
      return 0; 
  
    while (a > 1) 
    { 
        // q is quotient 
        int q = a / m; 
        int t = m; 
  
        // m is remainder now, process same as 
        // Euclid's algo 
        m = a % m, a = t; 
        t = y; 
  
        // Update y and x 
        y = x - q * y; 
        x = t; 
    } 
  
    // Make x positive 
    if (x < 0) 
       x += m0; 
  
    return x; 
} 

long long dfs(int cur, int par, vector<vector<int> >& adj, int k){
    long long res = 1;
    int kk = k - 1;
    if(par != -1) kk--;
    if(kk < adj[cur].size() - 1 ) return 0;
    long long mul = (fact[kk] * modInverse(fact[kk - adj[cur].size() + 1], MOD)) % MOD;
    if(adj[cur].size() == 1 && par != -1){
        //cout << cur << ": " << res << endl;
        return res;
    }
    for(int i = 0; i < adj[cur].size(); i++){
        int nxt = adj[cur][i];
        if(nxt == par){
            kk++;
            continue;
        }
        res *= dfs(nxt, cur, adj, k); 
        res %= MOD;
    }
    //cout << cur << ": " << res << endl; 
    return (res * mul) % MOD;
}

int main(){
    int n, k;
    cin  >> n >> k;
    fact[0] = 1;
    for(int i = 1; i <= 1e5; i++) fact[i] = (i * fact[i - 1]) % MOD;
    vector<vector<int> > adj(n);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << k * dfs(0, -1, adj, k) << endl;
}