#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
 
template<class T, int SZ> struct LazySegTree {
    T sum[2*SZ], mn[2*SZ], lazy[2*SZ]; // set SZ to a power of 2
 
    LazySegTree() {
        memset (sum,0,sizeof sum);
        memset (mn,0,sizeof mn);
        memset (lazy,0,sizeof lazy);
    }
 
    void push(int ind, int L, int R) {
        sum[ind] += (R-L+1)*lazy[ind];
        mn[ind] += lazy[ind];
        if (L != R) lazy[2*ind] += lazy[ind], lazy[2*ind+1] += lazy[ind];
        lazy[ind] = 0;
    }
 
    void pull(int ind) {
        sum[ind] = sum[2*ind]+sum[2*ind+1];
        mn[ind] = min(mn[2*ind],mn[2*ind+1]);
    }
 
    void build() {
        for(int i = SZ-1;i>=0; i--){
            pull(i);
        }
    }
 
    T qsum(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (lo > R || L > hi) return 0;
        if (lo <= L && R <= hi) return sum[ind];
 
        int M = (L+R)/2;
        return qsum(lo,hi,2*ind,L,M) + qsum(lo,hi,2*ind+1,M+1,R);
    }
 
    T qmin(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (lo > R || L > hi) return INF;
        if (lo <= L && R <= hi) return mn[ind];
 
        int M = (L+R)/2;
        return min(qmin(lo,hi,2*ind,L,M), qmin(lo,hi,2*ind+1,M+1,R));
    }
 
    void upd(int lo, int hi, long long inc, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) {
            lazy[ind] = inc;
            push(ind,L,R);
            return;
        }
 
        int M = (L+R)/2;
        upd(lo,hi,inc,2*ind,L,M); upd(lo,hi,inc,2*ind+1,M+1,R);
        pull(ind);
    }
};
vector<vector<int>> graph;
template <class T, int V>
class HeavyLight {
  int parent[V], heavy[V], depth[V];
  int root[V], treePos[V];
  LazySegTree<T, V> tree;
 
  template <class G>
  int dfs(const G& graph, int v) {
    int size = 1, maxSubtree = 0;
    for (int u : graph[v]) if (u != parent[v]) {
      parent[u] = v;
      depth[u] = depth[v] + 1;
      int subtree = dfs(graph, u);
      if (subtree > maxSubtree) heavy[v] = u, maxSubtree = subtree;
      size += subtree;
    }
    return size;
  }
 
  template <class BinaryOperation>
  void processPath(int u, int v, BinaryOperation op) {
    for (; root[u] != root[v]; v = parent[root[v]]) {
      if (depth[root[u]] > depth[root[v]]) swap(u, v);
      op(treePos[root[v]], treePos[v] + 1);
    }
    if (depth[u] > depth[v]) swap(u, v);
    op(treePos[u], treePos[v] + 1);
  }
 
public:
  template <class G>
  void init(const G& graph) {
    int n = graph.size();
    fill_n(heavy, n, -1);
    parent[0] = -1;
    depth[0] = 0;
    dfs(graph, 0);
    for (int i = 0, currentPos = 0; i < n; ++i)
      if (parent[i] == -1 || heavy[parent[i]] != i)
        for (int j = i; j != -1; j = heavy[j]) {
          root[j] = i;
          treePos[j] = currentPos++;
        }
        tree.build();
  }
 
  void set(int v, const T& value) {
    tree.set(treePos[v], value);
  }
 
  void modifyPath(int u, int v, const T& value) {
    processPath(u, v, [this, &value](int l, int r) { tree.upd(l, r, value); });
  }
 
  long long queryPath(int u, int v) {
    long long res =0;
    processPath(u, v, [this, &res](int l, int r) { res += (tree.qsum(l, r)); });
    return res;
  }
};
 
HeavyLight<long long, (int)1e6> H;

vector<vector<int> > up, adj;
vector<set<pair<int, long long> > > val;
vector<int> tin, tout;
int l, timer;

void dfs(int v, int p){
    val[v].emplace(0, 0);
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i) up[v][i] = up[up[v][i-1]][i-1];
    for (int u : adj[v]) if(u != p) dfs(u, v);
    tout[v] = ++timer;
}

int parent(int v, int k){
    if(k == 0) return v;
    int i, p;
    for(i = 0, p = 1; p <= k; i++, p *= 2);
    --i; p /= 2;
    return parent(up[v][i], k - p);
}

void upd(int v, int t1, int t2, int inc){
    auto it = --val[v].upper_bound({t1, INF});
    if((it -> first) != t1){
        val[v].emplace(t1, it -> second);
        it = --val[v].upper_bound({t1, INF});
    }
    auto it2 = --val[v].upper_bound({t2, INF});
    if((it2 -> first) != t2) val[v].emplace(t2, it2 -> second); 
    vector<pair<int, int> > ins;
    for(; it != val[v].end() && (it -> first) < t2; ){
        ins.emplace_back(it -> first, (it -> second) + inc);
        it = val[v].erase(it);
    }
    for(auto& p: ins) val[v].insert(p);
}

int value(int v, int t1, int t2){
    auto it = --val[v].upper_bound({t1, INF});
    return it -> second;
}

int main(){
    int n, q;
    cin >> n >> q;
    adj.resize(2 * n);
    graph.resize(n);
    val.resize(2 * n);
    tin.resize(2 * n);
    tout.resize(2 * n);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        graph[v].push_back(u);
        graph[u].push_back(v);
    }
    cout << "here" << endl;
    adj[0].push_back(n);
    adj[n].push_back(0);    
    for(int i = n; i < 2 * n - 1; i++){
        adj[i].push_back(i + 1);
        adj[i + 1].push_back(i);
    }
    l = ceil(log2(2 * n));
    timer = 0;
    up.assign(2 * n, vector<int>(l + 1));
    int root = 2 * n - 1;
    //cout << "here" << endl;
    dfs(root, root);
    //cout << "here" << endl;
    H.init(graph);
    for(int i = 0; i < n; i++){
        int b;
        cin >> b;
        upd(i, tin[i], tout[i], b);
        H.modifyPath(i, i, b);
    }
    for(int i = 1; i <= q; i++){
        char type;
        cin >> type;
        if(type == '+'){
            int v, k;
            cin >> v >> k;
            v--;
            upd(parent(v, i), tin[v], tout[v], k);
            H.modifyPath(v, v, k);
        }
        else{
            int v;
            cin >> v;
            v--;
            if(tout[v] - tin[v] <= 1){
                cout << H.queryPath(v, parent(v, i - 1)) << "\n";
            }
            else{
                cout << value(parent(v, i - 1), tin[v], tout[v]) << "\n";
            }
        }
    }
}