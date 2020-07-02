#include<bits/stdc++.h>

using namespace std;

int n, n2;
vector<int> color, primes, first, last, eulerTree;
map<int, int> primeID;
vector<vector<int> > adj, factors;
vector<vector<int> > bit;
vector<bool> isPrime, visited;

void sieve(int n){
    isPrime.resize(n, 1);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i < n; i++){
        if(!isPrime[i]) continue;
        for(int j = 2*i; j < n; j+=i) isPrime[j] = false;
    }
    for(int i = 0, id = 0; i < n; ++i){
        if(isPrime[i]){
            primes.push_back(i);
            primeID[i] = id++;
        }
    }
}

void fillFactors(int n){
    factors.resize(n);
    for(int p: primes){
        for(int i = p; i < n; i+=p) factors[i].push_back(p);
    }
}

void eulerTour(int u){
    visited[u] = true;
    eulerTree.push_back(u);
    for(int i: adj[u]){
        if(!visited[i]){
            eulerTour(i);
        }
    }
    eulerTree.push_back(u);
}

void fillFirstLast(){
    first.resize(n, -1);
    last.resize(n, -1);
    for(int i = 0; i < n2; i++){
        int cur = eulerTree[i];
        if(first[cur] == -1) first[cur] = i;
        last[cur] = i;
    }
}

int sum(int t, int r) {
    t = primeID[t];
    int ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        ret += bit[t][r];
    return ret;
}

void add(int t, int idx, int delta) {
    t = primeID[t];
    for (; idx < n2; idx = idx | (idx + 1))
        bit[t][idx] += delta;
}

int sum(int t, int l, int r) {
    return sum(t, r) - sum(t, l - 1);
}

void build(){
    bit.resize(1229, vector<int>(n2, 0));
    for(int i = 0; i < n; i++){
        for(int f: factors[color[i]])
            add(f, first[i], 1);
    }
}

int main(){
    int q, u, v;
    sieve(1e4 + 1);
    for(int i = 0; i < 10; i++) cout << primes[i] << " "; cout << endl;
    fillFactors(1e4 + 1);
    for(int i = 2; i < 20; i++){cout << "factors of " << i << " : ";for(int f: factors[i]) cout << f << " "; cout << endl;}

    cin >> n;
    color.resize(n);
    adj.resize(n);
    for(int& c: color) cin >> c;
    for(int i = 0; i < n-1; i++){
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    visited.resize(n, 0);
    eulerTour(0);
    n2 = eulerTree.size();
    cout << "Euler : "; for(int i: eulerTree) cout << i << " "; cout << endl;
    fillFirstLast();
    for(int i = 0; i < n; i++) cout << i << ": " << first[i] << " to " << last[i] << endl; 
    build();
    while(true){cin >> q; if(q == -1) break; for(int i: bit[q]) cout << i << " "; cout << endl;}

    cin >> q;
    while(q--){
        int type, x, y, g;
        cin >> type;
        if(type == 1){
            cin >> x >> y;
            for(int f: factors[color[x-1]])
                add(f, first[x-1], -1);
            for(int f: factors[y])
                add(f, first[x-1], 1);
            color[x-1] = y;
        }
        else{
            cin >> x >> g;
            cout << sum(g, first[x-1], last[x-1]) << endl;
        }
    }
}