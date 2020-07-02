#include<bits/stdc++.h>

using namespace std;

vector<int> A, parents;
vector<long long>W;
vector<vector<int> > neighbor;
set<pair<long long, int>> toDelete;
 
void init(int n){
    neighbor.clear();
    A.resize(n);
    W.clear();
    W.resize(n);
    toDelete.clear();
    neighbor.resize(n);
}

void fillWeight(int cur, int parent){
    parents[cur] = parent;
    W[cur] = A[cur];
    for(int c: neighbor[cur]){
        if(c == parent) continue;
        fillWeight(c, cur);
        W[cur] += W[c];
    }
}

void deleteSub(int cur, set<int>& deleted){
    deleted.insert(cur);
    for(int c: neighbor[cur]){
        if(c != parents[cur]) deleteSub(c, deleted);
    }
}

void deleteParents(int cur, set<int>& deleted){
    if(cur == -1) return;
    deleted.insert(cur);
    deleteParents(parents[cur]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, x;
    cin >> t;
    while(t--){        
        cin >> n >> x;
        init(n);
        for(int& i: A) cin >> i;
        for(int i = 0; i < n - 1; ++i){
            int x, y;
            cin >> x >> y;
            neighbor[x - 1].push_back(y - 1);
            neighbor[y - 1].push_back(x - 1);
        }
        fillWeight(0, -1);
        for(int i = 0; i < n; ++i){
            if(W[i] < -x) toDelete.emplace(W[i], i);
        }
        long long profit = W[0];
        set<int> deleted;
        for(auto p: toDelete){
            int d = p.second;
            if(deleted.find(d) != deleted.end()) continue;
            profit -= (p.first + x);
            deleteSub(d, deleted);
            deleteParents(d, deleted);
        }
        cout << profit << endl;
    }
}