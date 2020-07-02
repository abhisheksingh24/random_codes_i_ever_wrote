#include<bits/stdc++.h>

using namespace std;

bool solve(string s){
    int l = s.size();
    for(int i = 0 ; i < l - 10; i++) if(s[i] == '8') return true;
    return false;
}

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        string s;
        cin >> s;
        if(solve(s)) cout << "YES\n";
        else cout << "NO\n";
    }
}