#include<bits/stdc++.h>

using namespace std;

int main(){
    long long n, m, k;
    cin >> n >> m >> k;
    vector<long long> p(m);
    for(auto& i: p) cin >> i;
    sort(p.begin(), p.end());
    int del = 0, op = 0;
    while(del < m){
        auto it = upper_bound(p.begin(), p.end(), ((p[del] - del + k - 1) / k) * k + del);
        if(it == p.end()) del = m;
        else del = it - p.begin();
        op++;
    }
    cout << op << endl;
}