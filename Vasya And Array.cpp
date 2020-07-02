#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    set<pair<int, int> > asc, desc;
    cin >> n >> m;
    vector<int> A(n, 1);
    while(m--){
        int t, l, r;
        cin >> t >> l >> r;
        l--; r--;
        if(t == 1) asc.emplace(l, r);
        else desc.emplace(l, r);
    }
    for(int i = 0; i < n - 1; i++){
        bool cont = false;
        for(auto p: asc){
            if(p.first <= i && p.second >= i + 1){
                cont = true;
                break;
            }
        }
        if(cont) continue;
        vector<pair<int, int> > toDel;
        for(auto p: desc){
            if(p.first <= i && p.second >= i + 1){
                toDel.emplace_back(p);
            }
        }
        for(auto p: toDel) desc.erase(p);
        if(toDel.empty()) continue;
        for(int j = 0; j <= i; j++) A[j]++;
    }
    if(desc.empty()){
        cout << "YES" << endl;
        for(int i: A) cout << i << " ";
        cout << endl;
    }
    else cout << "NO" << endl;
}
