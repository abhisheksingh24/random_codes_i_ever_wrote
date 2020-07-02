#include<bits/stdc++.h>
 
using namespace std;
 
const long long MOD = 987654319;

void gcdExtended(long long a, long long b, long long *x, long long *y) { 
    if (a == 0) { 
        *x = 0, *y = 1; 
        return; 
    } 
    long long x1, y1;
    gcdExtended(b%a, a, &x1, &y1);  
    *x = y1 - (b/a) * x1; 
    *y = x1; 
} 

long long modInv(long long a, long long m = MOD) { 
    long long x, y; 
    gcdExtended(a, m, &x, &y);  
    long long res = (x%m + m) % m; 
    return res;  
} 
 
long long power(long long base, long long exp){
    base %= MOD;
    if(exp == 0) return 1;
    if(exp % 2) return (base * power(base * base, exp / 2)) % MOD;
    return power(base * base, exp / 2);
}

int getP(int v, vector<int>& p){
    if(p[v] == v) return v;
    p[v] = getP(p[v], p);
    return p[v];
}

void merge(int u, int v, int w, vector<int>& m, vector<int>& p, vector<set<int> >& adj){
    u = getP(u, p); v = getP(v, p);
    if(u == v) return;
    if(adj[v].size() > adj[u].size()) swap(u, v);
    for(int i: adj[v]) adj[u].insert(i);
    adj[v].clear();
    p[v] = u;
    m[u] = w;
}
 
int solve(vector<set<pair<int, int> > >& graph, int M, int n){
    priority_queue<tuple<int, int, int> > pick;
    pick.emplace(0, 0, -1);
    long long res = 1, mm = 1;
    vector<int> m(n, 0), p(n), parent(n, -1);
    vector<set<int> > adj(n);
    set<pair<int, int> > pars;
    for(int i = 0; i < n; i++) p[i] = i, adj[i].insert(i);
    while(!pick.empty()){
        int u, v, w;
        tie(w, v, u) = pick.top();
        w = -w;
        if(w > M) return 0;
        pick.pop();

        vector<pair<int, int> > toMerge;
        for(auto par: pars){
            if(par.first > w) break;
            toMerge.push_back(par);
            mm *= power(modInv(M - par.first + 2), adj[par.second].size());
            mm %= MOD;
        }
        if(!toMerge.empty()){
            for(auto& par: toMerge) pars.erase(par);
            for(int i = 1; i < toMerge.size(); i++){
                int uu = toMerge[0].second, vv = toMerge[i].second;
                merge(uu, vv, w, m, p, adj);
            }
            int uu = getP(toMerge[0].second, p);
            m[uu] = w;
            pars.emplace(w, uu);
            mm *= power(M - w + 2, adj[uu].size());
            mm %= MOD;
        }

        res *= mm;
        res %= MOD;
        res *= modInv(M - m[getP(u, p)] + 2);
        res %= MOD;
        //cout << w << " " << v << " " << u << " at top\n";
        for(auto& par: pars){
            int pwr = adj[par.second].size();
            if(adj[par.second].count(u)) pwr--;
            res *= power(M - par.first + 2, pwr);
            res %= MOD;
        }

        m[v] = 0;
        pars.emplace(m[v], v);

        mm *= (M + 2);
        mm %= MOD;

        for(auto& ch: graph[v]){
            if(parent[v] == ch.second) continue;
            //cout << "inserting " << ch.first << " " << ch.second << " " << v << endl; 
            pick.emplace(-ch.first, ch.second, v);
            parent[ch.second] = v;
        }

    }
    return res;
}
 
int main(){
    int n, M;
    cin >> n >> M;
    vector<set<pair<int, int> > > graph(n);
    for(int i = 0; i < n - 1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        graph[u].emplace(w, v);
        graph[v].emplace(w, u);
    }
    cout << solve(graph, M, n) << endl;
}