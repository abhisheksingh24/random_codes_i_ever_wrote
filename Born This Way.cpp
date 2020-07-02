#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, m, ta, tb, k;
    cin >> n >> m >> ta >> tb >> k;
    vector<int> a(n), b(m);
    for(int& i: a) cin >> i;
    for(int& i: b) cin >> i;
    for(int& i: a) i += ta;
    if(k >= n){
        cout << -1 << endl;
        return 0;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i, j;
    for(i = 0, j = 0; i < n && j < m && min(i, j) <= k; ){
        if(b[j] < a[i]) j++;
        else i++;
    }
    if(j == m) cout << -1 << endl;
    else cout << b[j] + tb << endl;
}