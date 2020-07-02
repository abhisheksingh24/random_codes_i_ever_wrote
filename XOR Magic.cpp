#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for(int& i: a) cin >> i;
        while(q--){
            int l, r;
            cin >> l >> r;
            l--; r--;
            long long res = 0;
            for(int i = l; i <= r; i++){
                res += (a[i] ^ (i - l));
            }
            cout << res << endl;
        }
    }
}