#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, b;
    cin >> n >> b;
    set<pair<int, int> > s;
    for(int i = 1; i <= n; i++){
        int t; cin >> t; 
        s.emplace(-t, i);
    }
    while(b--){
        cout << (s.begin() -> second) << " ";
        auto cur = *s.begin();
        cur.first++;
        s.erase(s.begin());
        s.insert(cur);
    }
    cout << "\n";
}