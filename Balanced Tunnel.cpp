#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n), ex(n);
    for(int& i: a){
        cin >> i;
        i--;
    }
    for(int& i: b){
        cin >> i;
        i--;
    }
    for(int i = 0; i < n; i++) ex[b[i]] = i;
    int mx = -1;
    vector<bool> pen(n, false);
    for(int i = 0; i < n; i++){
        if(ex[a[i]] < mx) pen[a[i]] = true;
        else mx = ex[a[i]];
    }
    int res = 0;
    for(auto i: pen) res += i;
    cout << res << endl;
}