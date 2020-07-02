#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a, b;
    a.resize(n);
    b.resize(m);
    for(int& i: a) cin >> i;
    for(int& i: b) cin >> i;
    int mn = 0, mx = 0;
    for(int i = 0; i < n; i++) if(a[i] < a[mn]) mn = i;
    for(int i = 0; i < m; i++) if(b[i] > b[mx]) mx = i;
    for(int i = 0; i < n; i++) cout << i << " " << mx << endl;
    for(int i = 0; i < m; i++) if(i != mx) cout << mn << " " << i << endl;
}	
