#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    set<vector<int> > order;
    vector<vector<int> > mat(n + 1);
    for(int i = 1; i <= n; i++) mat[i].push_back(i);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) continue;
            if(i > j) order.insert({1, i, j});
            else order.insert({0, i, j});
        }
    }
    for(int i = n + 1; i <= n * n; i++){
        auto v = *order.begin();
        order.erase(order.begin());
        int x = v[1], y = v[2];
        v[0] += mat[y].size();
        mat[x].push_back(i);
        order.insert(v);
    }
    for(int i = 1; i <= n; i++){
        auto row = mat[i];
        for(int j: row) cout << j << " ";
        cout << endl;
    }
}