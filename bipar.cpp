#include<bits/stdc++.h>

using namespace std;

vector<set<int> > G;
  vector<int> L, R, Viz;

struct BipartiteMatcher {
  
  /*BipartiteMatcher(int n, int m) :
  G(n), L(n, -1), R(m, -1), Viz(n) {}*/
  
  void AddEdge(int a, int b) {
    G[a].insert(b);
  }
  
  bool Match(int node) {
    if (Viz[node])
      return false;
    Viz[node] = true;
    
    for (auto vec : G[node]) {
      if (R[vec] == -1) {
        L[node] = vec;
        R[vec] = node;
        return true;
      }
    }
    
    for (auto vec : G[node]) {
      if (Match(R[vec])) {
        L[node] = vec;
        R[vec] = node;
        return true;
      }
    }
    
    return false;
  }
  
  int Solve() {
    int ok = true;
    while (ok--) {
      fill(Viz.begin(), Viz.end(), 0);
      for (int i = 0; i < (int)L.size(); ++i)
        if (L[i] == -1)
          ok |= Match(i);
    }
    
    int ret = 0;
    for (int i = 0; i < L.size(); ++i)
      ret += (L[i] != -1);
    return ret;
  }
};

int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    BipartiteMatcher bm;
    G.resize(n);
    L.assign(n, -1);
    R.assign((1 << 20) + 1, -1);
    Viz.assign((1 << 20) + 1, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        set<int> val;
        val.insert(a[i] ^ b[i]);
        val.insert(a[i] & b[i]);
        val.insert(a[i] | b[i]);
        for(int j: val) bm.AddEdge(i, j);
    }
    bm.Solve();
    for(int i = 0; i < n; i++){
        if(L[i] == -1){
            cout << "impossible" << endl;
            return 0;
        } 
    }
    for(int i = 0; i < n; i++){
        if((a[i] ^ b[i]) == L[i]) cout << a[i] << " ^ " << b[i] << " = " << L[i] << endl;
        else if((a[i] & b[i]) == L[i]) cout << a[i] << " & " << b[i] << " = " << L[i] << endl;
        else  cout << a[i] << " | " << b[i] << " = " << L[i] << endl;
    }
}