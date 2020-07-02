#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, m , h;
    cin >> n >> m >> h;
    vector<int> a(m), b(n);
    vector<vector<int> > he(n, vector<int>(m));
    for(int& i: a) cin >> i;
    for(int& i: b) cin >> i;
    for(auto& r: he){
        for(int& i: r) cin >> i;
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(he[i][j] == 0) cout << 0 << " ";
            else cout << min(b[i], a[j]) << " ";
        }
        cout << endl;
    }
}