#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, a, x, b, y;
    cin >> n >> a >> x >> b >> y;
    a--; x--; b--; y--;
    while(a != x && b != y){
        if(a == b){
            cout << "YES\n";
            return 0;
        }
        a = (a + 1) % n;
        b = (b - 1 + n) % n;
    }
    if(a == b) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}