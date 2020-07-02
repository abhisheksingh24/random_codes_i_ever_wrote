#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > adj, child;
vector<int> parent, leaf;
map<pair<int, int>, int> val;
vector<tuple<int, int, int> > res;
const int root = 0;

void init(int r){
    for(int i: adj[r]){
        if(i == parent[r]) continue;
        child[r].push_back(i);
        parent[i] = r;
        init(i);
    }
    if(child[r].empty()) for(int i = r; i != -1; i = parent[i]) leaf[i] = r;
}

bool possible(int r){
    if(adj[r].size() == 2) return false;
    for(int ch: child[r]) if(!possible(ch)) return false;
    return true;
}

int otherChild(int r, int c){
    for(int ch: child[r]) if(ch != c) return ch;
}

void add(int u, int l, int vall){
    vector<int> ll;
    for(int ch: child[u]){
        if(ll.size() == 2) break;
        if(leaf[ch] != l) ll.push_back(leaf[ch]);
    }
    if(ll.size() < 2){
        ll.push_back(leaf[otherChild(parent[u], u)]);
        //cout << u << " other " << otherChild(parent[u], u) << endl;
    }
    //cout << u << ": " << l << " " << ll[0] << " " << ll[1] << " " << endl;
    res.emplace_back(l, ll[0], vall / 2);
    res.emplace_back(l, ll[1], vall / 2);
    res.emplace_back(ll[1], ll[0], -vall / 2);
}

void solve(int cur){
    for(int ch: child[cur]){
        int v = val[make_pair(min(ch, cur), max(ch, cur))];
        add(cur, leaf[ch], v);
        if(ch != leaf[ch]) add(ch, leaf[ch], -v);
        solve(ch);
    }
}

int main(){
    int n;
    cin >> n;
    adj.resize(n);
    parent.resize(n);
    child.resize(n);
    leaf.resize(n);
    for(int i = 0; i < n - 1; i++){
        int u, v, vall;
        cin >> u >> v >> vall;
        u--; v--;
        if(u > v) swap(u, v);
        val[make_pair(u, v)] = vall;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    parent[root] = -1;
    init(root);
    //for(int i: leaf)cout << i << " "; cout <<endl;
    if(n == 2){
        cout << "YES" << endl;
        cout << 1 << endl;
        cout << 1 << " " << 2 << " " <<  val[make_pair(0, 1)] << endl;
        return 0;
    }
    if(!possible(root)){
        cout << "NO" << endl;
        return 0;
    }
    solve(root);
    cout << "YES" << endl;
    cout << res.size() << endl;
    for(auto t: res) cout << get<0>(t) + 1 << " " << get<1>(t) + 1 << " " << get<2>(t) << endl;
}