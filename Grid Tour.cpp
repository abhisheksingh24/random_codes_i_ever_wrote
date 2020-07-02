#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        if(gcd(n, k) > 1 || gcd(m, k) > 1){
            cout << "-1" << endl;
            continue;
        }
        cout << (long long)n * m << endl;
    }
}