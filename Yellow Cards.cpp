#include<bits/stdc++.h>

using namespace std;

int main(){
    int a1, a2, k1, k2, n, nn, mn, mx;
    cin >> a1 >> a2 >> k1 >> k2 >> n;
    nn = n;
    nn -= (k1 - 1) * a1;
    nn -= (k2 - 1) * a2;
    mn = max(0, nn);
    nn = n;
    if(k1 > k2) swap(k1, k2), swap(a1, a2);
    mx = min(a1, nn / k1);
    nn -= mx * k1;
    mx += min(a2, nn / k2);
    cout << mn << " " << mx << endl;;
}