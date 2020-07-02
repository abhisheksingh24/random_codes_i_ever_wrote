#include<bits/stdc++.h>

using namespace std;

int diff(int a, int b){
    return max(a, b) - min(a, b);
}

int main(){
    int t, w;
    cin >> t >> w;
    for(int tt = 1; tt <= t; ++tt){
        vector<long long> rep(7);
        for(int i = 1; i <= 6; i++){
            cout << i << endl;
            cout.flush();
            cin >> rep[i];
        }
        vector<long long> r(7);
        for(int i = 3; i <= 6; ++i){
            r[i] = rep[i] - 3 * rep[i - 1] + 2 * rep[i - 2];
        }
        
    }
}