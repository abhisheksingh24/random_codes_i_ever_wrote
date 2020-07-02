#include<bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int main(){
    int w, h;
    cin >> w >> h;
    long long res = 4;
    for(int i = 1; i < w; i++) res = (res * 2) % MOD;
    for(int i = 1; i < h; i++) res = (res * 2) % MOD;
    cout << res << endl;
}