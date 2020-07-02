#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll GCD(ll a, ll b){
    if(b == 0) return a;
    return GCD(b, a % b);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll l, r, g;
        cin >> l >> r >> g;
        l = ((l + g - 1) / g) * g;
        r = (r / g) * g;
        ll gcd = l;
        bool all = false;
        for(ll i = l; i <= r; i += g){
            gcd = GCD(gcd, i);
            if(gcd == g){
                all = true;
                break;
            }
        }
        if(all) cout << (r - l) / g + 1 << endl;
        else cout << 0 << endl;
    }
}