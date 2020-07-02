#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > adj, children;
vector<int> parent, xorsum, a;
vector<long long> dp;

const long long MOD = 1e9 + 7;
int x;

void fillParentsAndChildren(int curRoot, int curParent){
    parent[curRoot] = curParent;
    for(int c: adj[curRoot]){
        if(c==curParent) continue;
        children[curRoot].push_back(c);
        fillParentsAndChildren(c, curRoot);
    }
}

void fillXOR(int cur){
    xorsum[cur] = a[cur];
    for(int c: children[cur]){
        fillXOR(c);
        xorsum[cur] = xorsum[cur] ^ xorsum[c];
    }
}

long long power(long long b, int exp){
    b = b % MOD;
    if(exp == 0) return b;
    if(exp % 2) return (b*power(b*b, exp/2)) % MOD;
    return power(b*b, exp/2);
}

long long solve(int cur){
    if(children[cur].empty()) return a[cur] == x;
    if(dp[cur] != -1) return dp[cur];
    long long res = 0, zer = 0, ex = 0;
    for(int c: children[cur]){
        long long s = solve(c);
        if(s==0) continue;
        if(res = 0) res = s;
        else res = (res * s) % MOD;
        if(xorsum[c] == x) ++ex;
        if(xorsum[c] == 0) ++zer;
    }
    res = (res * power(2, zer)) % MOD;
    if(ex > 0) res = (res * power(2, ex - 1)) % MOD;
    dp[cur] = res;
    return res;
}

int main(){
    int n, u, v;
    cin >> n >> x;
    adj.resize(n);
    a.resize(n);
    children.resize(n);
    parent.resize(n);
    dp.resize(n, -1);
    xorsum.resize(n);
    for(int& i: a) cin >> i;
    for(int i = 0; i < n-1; i++){
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int root = 0;
    fillParentsAndChildren(root, -1);
    fillXOR(root);
    if(xorsum[root] == x || xorsum[root] == 0) cout << solve(root) << endl;
    else cout << 0 << endl;
}