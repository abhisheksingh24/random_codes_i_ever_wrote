#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    n = (1 << n);
    vector<bool> done(n, false);
    if(x < n) done[x] = true;
    vector<int> b, a;
    for(int i = 1; i < n; i++){
        if(done[i]) continue;
        b.push_back(i);
        done[i] = true;
        if((i ^ x) < n) done[i ^ x] = true;
    }
    if(!b.empty()) a.push_back(b[0]);
    for(int i = 1; i < b.size(); i++) a.push_back(b[i] ^ b[i-1]);
    cout << a.size() << endl;
    for(int i: a) cout << i << " ";
    cout << endl;
}