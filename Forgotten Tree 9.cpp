#include<bits/stdc++.h>

using namespace std;

bool query(int x, int a, int b){
    cout << "Q " << x << " " << a << " " << b << endl;
    string rep;
    cin >> rep;
    return rep == "Yes";
}

void dfs(int l, int r, int root, vector<int>& parent){
    if(l > r) return;
    if(l == r){
        parent[l - 1] = root;
        return;
    }
    vector<int> order;
    for(int i = l; i <= r; i++) order.push_back(i);
    random_shuffle(order.begin(), order.end());
    int cur;
    for(int i: order) if(query(i, l, r)) {
        cur = i;
        break;
    }
    parent[cur - 1] = root;
    dfs(l, cur - 1, cur, parent);
    dfs(cur + 1, r, cur, parent);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> parent(n);
        dfs(1, n, -1, parent);
        cout << "A";
        for(int p: parent) cout << " " << p;
        cout << endl;
    }
}