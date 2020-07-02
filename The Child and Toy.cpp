#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, m, x, y;
    cin >> n >> m;
    vector<int> v;
    v.resize(n);
    for(int& i: v) cin >> i;
    long long res = 0;
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        //cout << min(v[x], v[y]) << " : " << res << endl;
        if(v[x-1] < v[y-1]) res+=v[x-1];
        else res+=v[y-1];
    }
    cout << res << endl;
}