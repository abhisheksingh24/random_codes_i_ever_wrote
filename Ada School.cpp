#include<bits/stdc++.h>

using namespace std;

int main(){
    int t, n, m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        if(n%2 && m%2) cout << "NO\n";
        else cout << "YES\n";
    }
}